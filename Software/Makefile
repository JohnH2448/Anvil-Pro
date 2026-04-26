ROOT := ..

CROSS ?= riscv32-unknown-elf
CC := $(CROSS)-gcc
OBJCOPY := $(CROSS)-objcopy
OBJDUMP := $(CROSS)-objdump

TARGET := program
ELF := $(TARGET).elf
ANALYSIS_ELF := $(TARGET).analysis.elf
MAP := $(TARGET).map
ANALYSIS_MAP := $(TARGET).analysis.map
TEXT_BIN := $(TARGET).text.bin
RAW_HEX := $(TARGET).raw.hex
FINAL_HEX := $(ROOT)/Core/Memory/Instructions.hex
GENERATED_DIR := generated
INIT_DATA := $(GENERATED_DIR)/init_data.S
INIT_STUB := $(GENERATED_DIR)/init_data_stub.S
LINKER_ANALYSIS := $(GENERATED_DIR)/linker.analysis.ld
LINKER_FINAL := $(GENERATED_DIR)/linker.final.ld

SRCS := crt0.S main.c syscalls.c
LINKER := linker.ld
INITGEN := anvil_initgen.py
HEX_CONVERTER := $(ROOT)/Test/Automation/hex_to_four_word.py

ARCH_FLAGS := -march=rv32i_zicsr -mabi=ilp32
CFLAGS := \
	$(ARCH_FLAGS) \
	-O2 \
	-ffreestanding \
	-fno-builtin \
	-fno-pic \
	-fno-common \
	-fomit-frame-pointer \
	-fno-stack-protector \
	-fno-asynchronous-unwind-tables \
	-fno-unwind-tables

LDFLAGS := \
	--specs=nano.specs \
	-nostartfiles \
	-nostdlib \
	-Wl,--gc-sections \
	-Wl,-Map,$(MAP)

ANALYSIS_LDFLAGS := \
	--specs=nano.specs \
	-nostartfiles \
	-nostdlib \
	-Wl,-T,$(LINKER_ANALYSIS) \
	-Wl,--unresolved-symbols=ignore-all \
	-Wl,-Map,$(ANALYSIS_MAP)

FINAL_LDFLAGS := \
	$(LDFLAGS) \
	-Wl,-T,$(LINKER_FINAL)

.PHONY: all clean hex

all: hex

hex: $(FINAL_HEX)

$(GENERATED_DIR):
	mkdir -p $@

$(LINKER_ANALYSIS): $(LINKER) | $(GENERATED_DIR)
	$(CC) -E -P -x c $(LINKER) -o $@

$(LINKER_FINAL): $(LINKER) | $(GENERATED_DIR)
	$(CC) -E -P -x c -DNOLOAD_INIT $(LINKER) -o $@

$(INIT_STUB): | $(GENERATED_DIR)
	printf '%s\n' '    .section .text.init_data, "ax", @progbits' '    .globl __anvil_init_data' '    .type __anvil_init_data, @function' '__anvil_init_data:' '    ret' '    .size __anvil_init_data, . - __anvil_init_data' > $@

$(ANALYSIS_ELF): $(SRCS) $(INIT_STUB) $(LINKER_ANALYSIS)
	$(CC) $(CFLAGS) $(ANALYSIS_LDFLAGS) $(SRCS) $(INIT_STUB) -lc -lgcc -o $@

$(INIT_DATA): $(ANALYSIS_ELF) $(INITGEN) | $(GENERATED_DIR)
	python3 $(INITGEN) $(ANALYSIS_ELF) $(INIT_DATA) --objdump $(OBJDUMP) --objcopy $(OBJCOPY)

$(ELF): $(SRCS) $(INIT_DATA) $(LINKER_FINAL)
	$(CC) $(CFLAGS) $(FINAL_LDFLAGS) $(SRCS) $(INIT_DATA) -lc -lgcc -o $@

$(TEXT_BIN): $(ELF)
	$(OBJCOPY) -O binary --only-section=.text $< $@

$(RAW_HEX): $(TEXT_BIN)
	python3 -c "from pathlib import Path; data=Path('$(TEXT_BIN)').read_bytes(); data += b'\0' * ((4 - len(data) % 4) % 4); Path('$(RAW_HEX)').write_text(''.join(f'{int.from_bytes(data[i:i+4], \"little\"):08x}\n' for i in range(0, len(data), 4)))"

$(FINAL_HEX): $(RAW_HEX) $(HEX_CONVERTER)
	cp $(RAW_HEX) $(FINAL_HEX)
	python3 $(HEX_CONVERTER) $(FINAL_HEX)

clean:
	rm -f $(ELF) $(ANALYSIS_ELF) $(MAP) $(ANALYSIS_MAP) $(TEXT_BIN) $(RAW_HEX)
	rm -rf $(GENERATED_DIR)
