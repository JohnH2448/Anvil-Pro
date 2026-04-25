ROOT := ..

CROSS ?= riscv32-unknown-elf
CC := $(CROSS)-gcc
OBJCOPY := $(CROSS)-objcopy

TARGET := program
ELF := $(TARGET).elf
MAP := $(TARGET).map
TEXT_BIN := $(TARGET).text.bin
RAW_HEX := $(TARGET).raw.hex
FINAL_HEX := $(ROOT)/Core/Memory/Instructions.hex

SRCS := crt0.S main.c syscalls.c
LINKER := linker.ld
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
	-nostartfiles \
	-nostdlib \
	-Wl,-T,$(LINKER) \
	-Wl,--gc-sections \
	-Wl,-Map,$(MAP)

.PHONY: all clean hex

all: hex

hex: $(FINAL_HEX)

$(ELF): $(SRCS) $(LINKER)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRCS) -lgcc -o $@

$(TEXT_BIN): $(ELF)
	$(OBJCOPY) -O binary --only-section=.text $< $@

$(RAW_HEX): $(TEXT_BIN)
	python3 -c "from pathlib import Path; data=Path('$(TEXT_BIN)').read_bytes(); data += b'\0' * ((4 - len(data) % 4) % 4); Path('$(RAW_HEX)').write_text(''.join(f'{int.from_bytes(data[i:i+4], \"little\"):08x}\n' for i in range(0, len(data), 4)))"

$(FINAL_HEX): $(RAW_HEX) $(HEX_CONVERTER)
	cp $(RAW_HEX) $(FINAL_HEX)
	python3 $(HEX_CONVERTER) $(FINAL_HEX)

clean:
	rm -f $(ELF) $(MAP) $(TEXT_BIN) $(RAW_HEX)
