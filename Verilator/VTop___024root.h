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
        CData/*3:0*/ Top__DOT__freeTag1;
        CData/*6:0*/ Top__DOT__upperSource1Status;
        CData/*6:0*/ Top__DOT__upperSource2Status;
        CData/*6:0*/ Top__DOT__lowerSource1Status;
        CData/*6:0*/ Top__DOT__lowerSource2Status;
        CData/*6:0*/ Top__DOT__oldLowerStatus;
        CData/*6:0*/ Top__DOT__oldUpperStatus;
        CData/*0:0*/ Top__DOT__destRegLoad1;
        CData/*0:0*/ Top__DOT__destRegLoad2;
        CData/*0:0*/ Top__DOT__instructionConsumed1;
        CData/*0:0*/ Top__DOT__instructionConsumed2;
        CData/*0:0*/ Top__DOT__outputJal;
        CData/*0:0*/ Top__DOT__taken;
        CData/*0:0*/ Top__DOT__bpUpdateValid1;
        CData/*0:0*/ Top__DOT__stall;
        CData/*0:0*/ Top__DOT__redirect;
        CData/*0:0*/ Top__DOT__mispredict1;
        CData/*0:0*/ Top__DOT__memFreeSlot;
        CData/*0:0*/ Top__DOT__outputValid;
        CData/*3:0*/ Top__DOT__memoryQueue__DOT__tailPointer;
        CData/*3:0*/ Top__DOT__memoryQueue__DOT__byteSelectTransform;
        CData/*2:0*/ Top__DOT__memoryQueue__DOT__unnamedblk3__DOT__unnamedblk5__DOT__index;
        CData/*0:0*/ Top__DOT__placeholderDMEM__DOT__requestPending;
        CData/*0:0*/ Top__DOT__placeholderDMEM__DOT__latchedWriteEnable;
        CData/*3:0*/ Top__DOT__placeholderDMEM__DOT__latchedByteSelect;
        CData/*0:0*/ Top__DOT__placeholderDMEM__DOT__delayCounter;
        CData/*0:0*/ Top__DOT__placeholderDMEM__DOT__validRequest;
        CData/*1:0*/ Top__DOT__reorderBuffer__DOT__retireCount;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__headPointer;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__tailPointer;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__redirectPointer;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__nextHeadPointer;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__nextTailPointer;
        CData/*6:0*/ Top__DOT__operandSelect__DOT__upperSource1Status;
        CData/*6:0*/ Top__DOT__operandSelect__DOT__upperSource2Status;
        CData/*6:0*/ Top__DOT__operandSelect__DOT__lowerSource1Status;
        CData/*6:0*/ Top__DOT__operandSelect__DOT__lowerSource2Status;
        CData/*0:0*/ Top__DOT__execute__DOT__redirect1;
        CData/*0:0*/ Top__DOT__execute__DOT__redirect2;
        CData/*0:0*/ Top__DOT__execute__DOT__illegal2;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__illegal2;
        CData/*4:0*/ Top__DOT__decodeIssue__DOT__destinationRegister2;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__illegal1;
        CData/*4:0*/ Top__DOT__decodeIssue__DOT__destinationRegister1;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__instructionsValid;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__postRedirectCounter;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__internalBadData;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__block1;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__block2;
        CData/*1:0*/ Top__DOT__decodeIssue__DOT__bypassEnable;
        CData/*1:0*/ Top__DOT__decodeIssue__DOT__staleVector1;
        CData/*1:0*/ Top__DOT__decodeIssue__DOT__staleVector2;
        CData/*0:0*/ __Vtrigprevexpr___TOP__Top__DOT__taken__0;
        CData/*0:0*/ __VstlDidInit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__Top__DOT__taken__1;
        CData/*0:0*/ __VicoDidInit;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__Top__DOT__taken__2;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
    };
    struct {
        SData/*11:0*/ Top__DOT__rstBus1;
        SData/*11:0*/ Top__DOT__rstBus2;
        SData/*11:0*/ Top__DOT__rstBus3;
        SData/*9:0*/ Top__DOT__placeholderDMEM__DOT__unnamedblk2__DOT__wordIndex;
        VL_OUT(tohost,31,0);
        IData/*31:0*/ Top__DOT__requestPC1;
        IData/*31:0*/ Top__DOT__requestPC2;
        IData/*31:0*/ Top__DOT__precalcAddress;
        IData/*31:0*/ Top__DOT__branchProgramCounter;
        IData/*31:0*/ Top__DOT__redirectVector;
        IData/*31:0*/ Top__DOT__instruction1;
        IData/*31:0*/ Top__DOT__instruction2;
        IData/*31:0*/ Top__DOT__programCounter;
        IData/*31:0*/ Top__DOT__finalOutputData;
        VlWide<4>/*127:0*/ Top__DOT__lowFetchData;
        VlWide<4>/*127:0*/ Top__DOT__highFetchData;
        IData/*31:0*/ Top__DOT__placeholderDMEM__DOT__latchedAddress;
        IData/*31:0*/ Top__DOT__placeholderDMEM__DOT__latchedStoreData;
        IData/*31:0*/ Top__DOT__placeholderDMEM__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ Top__DOT__placeholderDMEM__DOT__unnamedblk2__DOT__nextLoadData;
        IData/*31:0*/ Top__DOT__execute__DOT__result1;
        IData/*31:0*/ Top__DOT__execute__DOT__result2;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__IR1;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__IR2;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__PC1;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__PC2;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__target1;
        IData/*31:0*/ Top__DOT__decodeIssue__DOT__target2;
        IData/*31:0*/ Top__DOT__walkingWindow__DOT__lastLowWindow;
        IData/*31:0*/ Top__DOT__walkingWindow__DOT__lastHighWindow;
        IData/*31:0*/ Top__DOT__instructionMemory__DOT__redirectAddress;
        IData/*31:0*/ __VactIterCount;
        QData/*41:0*/ Top__DOT__resolvedInstruction1;
        QData/*41:0*/ Top__DOT__resolvedInstruction2;
        VlWide<4>/*111:0*/ Top__DOT__payload1;
        VlWide<4>/*106:0*/ Top__DOT__payload2;
        QData/*42:0*/ Top__DOT__instructionPacket1;
        QData/*42:0*/ Top__DOT__instructionPacket2;
        VlWide<5>/*152:0*/ Top__DOT__exPayload1;
        VlWide<5>/*149:0*/ Top__DOT__exPayload2;
        QData/*41:0*/ Top__DOT__resultPayload1;
        QData/*41:0*/ Top__DOT__resultPayload2;
        VlWide<3>/*77:0*/ Top__DOT__memPayload;
        QData/*41:0*/ Top__DOT__completedMemory;
        VlWide<3>/*70:0*/ Top__DOT__memBusOut;
        VlWide<3>/*68:0*/ Top__DOT__storeBus1;
        VlWide<3>/*68:0*/ Top__DOT__storeBuffer__DOT____Vlvbound_hf16badd7__0;
        QData/*32:0*/ Top__DOT__placeholderDMEM__DOT__memBusInRegister;
        VlWide<5>/*152:0*/ Top__DOT__operandSelect__DOT__exPayloadCandidate1;
        VlWide<5>/*149:0*/ Top__DOT__operandSelect__DOT__exPayloadCandidate2;
        VlWide<4>/*111:0*/ Top__DOT__decodeIssue__DOT__tempPayload2;
        VlWide<4>/*111:0*/ Top__DOT__decodeIssue__DOT__tempPayload1;
        VlWide<4>/*111:0*/ Top__DOT__decodeIssue__DOT__finalUpperPayload;
        VlWide<4>/*106:0*/ Top__DOT__decodeIssue__DOT__finalLowerPayload;
        VlUnpacked<VlWide<3>/*81:0*/, 8> Top__DOT__memoryQueue__DOT__queueEntry;
        VlUnpacked<VlWide<3>/*68:0*/, 10> Top__DOT__storeBuffer__DOT__shiftEntries;
        VlUnpacked<IData/*31:0*/, 1024> Top__DOT__placeholderDMEM__DOT__memory;
        VlUnpacked<VlWide<3>/*74:0*/, 16> Top__DOT__reorderBuffer__DOT__reorderBuffer;
        VlUnpacked<CData/*3:0*/, 16> Top__DOT__reorderBuffer__DOT__sortGrid;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 3>, 16> Top__DOT__reorderBuffer__DOT__maskGrid;
        VlUnpacked<CData/*6:0*/, 32> Top__DOT__registerStatusTable__DOT__registerStatusTable;
        VlUnpacked<IData/*31:0*/, 32> Top__DOT__registerFile__DOT__registerFile;
        VlUnpacked<CData/*1:0*/, 64> Top__DOT__branchPredictor__DOT__counterTable;
        VlUnpacked<VlWide<4>/*127:0*/, 256> Top__DOT__instructionMemory__DOT__memory;
    };
    VlTriggerVec<2> __VstlTriggered;
    VlTriggerVec<2> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

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
