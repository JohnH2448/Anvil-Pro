// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        CData/*0:0*/ Top__DOT__triggerStore;
        CData/*4:0*/ Top__DOT__nextFreeSlots;
        CData/*6:0*/ Top__DOT__upperSource1Status;
        CData/*6:0*/ Top__DOT__upperSource2Status;
        CData/*6:0*/ Top__DOT__lowerSource1Status;
        CData/*6:0*/ Top__DOT__lowerSource2Status;
        CData/*0:0*/ Top__DOT__instructionConsumed1;
        CData/*0:0*/ Top__DOT__instructionConsumed2;
        CData/*0:0*/ Top__DOT__redirect;
        CData/*0:0*/ Top__DOT__reorderBuffer__DOT__storeACK;
        CData/*1:0*/ Top__DOT__reorderBuffer__DOT__retireCount;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__freeSlots;
        CData/*0:0*/ Top__DOT__reorderBuffer__DOT__outgoingStore;
        CData/*0:0*/ Top__DOT__execute__DOT__illegal1;
        CData/*0:0*/ Top__DOT__execute__DOT__illegal2;
        CData/*4:0*/ Top__DOT__decodeIssue__DOT__issue1AgeTag;
        CData/*4:0*/ Top__DOT__decodeIssue__DOT__issue2AgeTag;
        CData/*4:0*/ Top__DOT__decodeIssue__DOT__destinationRegister2;
        CData/*4:0*/ Top__DOT__decodeIssue__DOT__destinationRegister1;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__instructionsValid;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__postRedirectCounter;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__internalBadData;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__block1;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__block2;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ Top__DOT__upperROBData1;
        IData/*31:0*/ Top__DOT__upperROBData2;
        IData/*31:0*/ Top__DOT__lowerROBData1;
        IData/*31:0*/ Top__DOT__lowerROBData2;
        IData/*31:0*/ Top__DOT__requestPC1;
        IData/*31:0*/ Top__DOT__requestPC2;
        IData/*31:0*/ Top__DOT__redirectVector;
        IData/*31:0*/ Top__DOT__instruction1;
        IData/*31:0*/ Top__DOT__instruction2;
        IData/*31:0*/ Top__DOT__programCounter;
        VlWide<4>/*127:0*/ Top__DOT__lowFetchData;
        VlWide<4>/*127:0*/ Top__DOT__highFetchData;
        IData/*31:0*/ Top__DOT__reorderBuffer__DOT__debugCycle;
        IData/*31:0*/ Top__DOT__registerFile__DOT__debugCycle;
        IData/*31:0*/ Top__DOT__operandSelect__DOT__debugCycle;
        IData/*31:0*/ Top__DOT__execute__DOT__result1;
        IData/*31:0*/ Top__DOT__execute__DOT__result2;
        IData/*31:0*/ Top__DOT__execute__DOT__debugCycle;
        IData/*31:0*/ Top__DOT__execute__DOT__upperOperand1;
        IData/*31:0*/ Top__DOT__execute__DOT__upperOperand2;
        IData/*31:0*/ Top__DOT__execute__DOT__lowerOperand1;
        IData/*31:0*/ Top__DOT__execute__DOT__lowerOperand2;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__IR1;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__IR2;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__PC1;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__PC2;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__debugCycle;
        IData/*31:0*/ Top__DOT__walkingWindow__DOT__lastLowWindow;
        IData/*31:0*/ Top__DOT__walkingWindow__DOT__lastHighWindow;
        IData/*31:0*/ Top__DOT__walkingWindow__DOT__debugCycle;
        IData/*31:0*/ Top__DOT__instructionMemory__DOT__redirectAddress;
        IData/*31:0*/ Top__DOT__instructionMemory__DOT__nextAddress;
        IData/*31:0*/ __VactIterCount;
        QData/*42:0*/ Top__DOT__resolvedInstruction1;
    };
    struct {
        QData/*42:0*/ Top__DOT__resolvedInstruction2;
        VlWide<4>/*100:0*/ Top__DOT__payload1;
        VlWide<4>/*97:0*/ Top__DOT__payload2;
        QData/*43:0*/ Top__DOT__instructionPacket1;
        QData/*43:0*/ Top__DOT__instructionPacket2;
        VlWide<4>/*120:0*/ Top__DOT__exPayload1;
        VlWide<4>/*117:0*/ Top__DOT__exPayload2;
        QData/*42:0*/ Top__DOT__resultPayload1;
        QData/*42:0*/ Top__DOT__resultPayload2;
        VlWide<4>/*120:0*/ Top__DOT__operandSelect__DOT__exPayloadCandidate1;
        VlWide<4>/*117:0*/ Top__DOT__operandSelect__DOT__exPayloadCandidate2;
        VlWide<4>/*100:0*/ Top__DOT__decodeIssue__DOT__tempPayload2;
        VlWide<4>/*100:0*/ Top__DOT__decodeIssue__DOT__tempPayload1;
        VlWide<4>/*100:0*/ Top__DOT__decodeIssue__DOT__finalUpperPayload;
        VlWide<4>/*97:0*/ Top__DOT__decodeIssue__DOT__finalLowerPayload;
        VlUnpacked<VlWide<3>/*75:0*/, 16> Top__DOT__reorderBuffer__DOT__reorderBuffer;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 6>, 16> Top__DOT__reorderBuffer__DOT__forwardGrid;
        VlUnpacked<CData/*7:0*/, 32> Top__DOT__registerStatusTable__DOT__registerStatusTable;
        VlUnpacked<IData/*31:0*/, 32> Top__DOT__registerFile__DOT__registerFile;
        VlUnpacked<VlWide<4>/*127:0*/, 256> Top__DOT__instructionMemory__DOT__memory;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop___024root(VTop__Syms* symsp, const char* v__name);
    ~VTop___024root();
    VL_UNCOPYABLE(VTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
