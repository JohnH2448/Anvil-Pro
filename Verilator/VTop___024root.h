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
        CData/*3:0*/ Top__DOT__freeTag1;
        CData/*5:0*/ Top__DOT__upperSource1Status;
        CData/*5:0*/ Top__DOT__upperSource2Status;
        CData/*5:0*/ Top__DOT__lowerSource1Status;
        CData/*5:0*/ Top__DOT__lowerSource2Status;
        CData/*5:0*/ Top__DOT__oldLowerStatus;
        CData/*5:0*/ Top__DOT__oldUpperStatus;
        CData/*0:0*/ Top__DOT__upperInFlightLoad1;
        CData/*0:0*/ Top__DOT__upperInFlightLoad2;
        CData/*0:0*/ Top__DOT__lowerInFlightLoad1;
        CData/*0:0*/ Top__DOT__lowerInFlightLoad2;
        CData/*0:0*/ Top__DOT__destRegLoad1;
        CData/*0:0*/ Top__DOT__destRegLoad2;
        CData/*0:0*/ Top__DOT__instructionConsumed1;
        CData/*0:0*/ Top__DOT__instructionConsumed2;
        CData/*0:0*/ Top__DOT__redirect;
        CData/*0:0*/ Top__DOT__redirect1;
        CData/*0:0*/ Top__DOT__storeACK;
        CData/*0:0*/ Top__DOT__memFreeSlot;
        CData/*3:0*/ Top__DOT__memoryQueue__DOT__tailPointer;
        CData/*3:0*/ Top__DOT__memoryQueue__DOT__byteSelectTransform;
        CData/*0:0*/ Top__DOT__memoryQueue__DOT__storeTriggered;
        CData/*2:0*/ Top__DOT__memoryQueue__DOT__unnamedblk3__DOT__unnamedblk5__DOT__index;
        CData/*0:0*/ Top__DOT__placeholderDMEM__DOT__requestPending;
        CData/*0:0*/ Top__DOT__placeholderDMEM__DOT__latchedWriteEnable;
        CData/*3:0*/ Top__DOT__placeholderDMEM__DOT__latchedByteSelect;
        CData/*1:0*/ Top__DOT__placeholderDMEM__DOT__delayCounter;
        CData/*0:0*/ Top__DOT__placeholderDMEM__DOT__validRequest;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__headPointer;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__tailPointer;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__nextHeadPointer;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__nextTailPointer;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__freeEntries;
        CData/*4:0*/ Top__DOT__reorderBuffer__DOT__entries;
        CData/*0:0*/ Top__DOT__reorderBuffer__DOT__outgoingStore;
        CData/*3:0*/ Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex;
        CData/*5:0*/ Top__DOT__operandSelect__DOT__upperSource1Status;
        CData/*5:0*/ Top__DOT__operandSelect__DOT__upperSource2Status;
        CData/*5:0*/ Top__DOT__operandSelect__DOT__lowerSource1Status;
        CData/*5:0*/ Top__DOT__operandSelect__DOT__lowerSource2Status;
        CData/*0:0*/ Top__DOT__execute__DOT__illegal1;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__illegal2;
        CData/*4:0*/ Top__DOT__decodeIssue__DOT__destinationRegister2;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__illegal1;
        CData/*4:0*/ Top__DOT__decodeIssue__DOT__destinationRegister1;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__instructionsValid;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__postRedirectCounter;
        CData/*0:0*/ Top__DOT__decodeIssue__DOT__internalBadData;
        CData/*1:0*/ Top__DOT__decodeIssue__DOT__bypassEnable;
        CData/*1:0*/ Top__DOT__decodeIssue__DOT__staleVector1;
        CData/*1:0*/ Top__DOT__decodeIssue__DOT__staleVector2;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ Top__DOT__rstBus1;
        SData/*11:0*/ Top__DOT__rstBus2;
        SData/*11:0*/ Top__DOT__rstBus3;
        SData/*9:0*/ Top__DOT__placeholderDMEM__DOT__unnamedblk2__DOT__wordIndex;
        IData/*31:0*/ Top__DOT__requestPC1;
        IData/*31:0*/ Top__DOT__requestPC2;
    };
    struct {
        IData/*31:0*/ Top__DOT__redirectVector;
        IData/*31:0*/ Top__DOT__instruction1;
        IData/*31:0*/ Top__DOT__instruction2;
        IData/*31:0*/ Top__DOT__programCounter;
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
        IData/*31:0*/ Top__DOT__walkingWindow__DOT__lastLowWindow;
        IData/*31:0*/ Top__DOT__walkingWindow__DOT__lastHighWindow;
        IData/*31:0*/ Top__DOT__instructionMemory__DOT__redirectAddress;
        IData/*31:0*/ Top__DOT__instructionMemory__DOT__nextAddress;
        IData/*31:0*/ __VactIterCount;
        QData/*41:0*/ Top__DOT__resolvedInstruction1;
        QData/*41:0*/ Top__DOT__resolvedInstruction2;
        VlWide<4>/*107:0*/ Top__DOT__payload1;
        VlWide<4>/*104:0*/ Top__DOT__payload2;
        QData/*42:0*/ Top__DOT__instructionPacket1;
        QData/*42:0*/ Top__DOT__instructionPacket2;
        VlWide<4>/*119:0*/ Top__DOT__exPayload1;
        VlWide<4>/*116:0*/ Top__DOT__exPayload2;
        QData/*41:0*/ Top__DOT__resultPayload1;
        QData/*41:0*/ Top__DOT__resultPayload2;
        VlWide<3>/*77:0*/ Top__DOT__memPayload;
        QData/*41:0*/ Top__DOT__completedMemory;
        VlWide<3>/*70:0*/ Top__DOT__memBusOut;
        QData/*32:0*/ Top__DOT__placeholderDMEM__DOT__memBusInRegister;
        VlWide<4>/*119:0*/ Top__DOT__operandSelect__DOT__exPayloadCandidate1;
        VlWide<4>/*116:0*/ Top__DOT__operandSelect__DOT__exPayloadCandidate2;
        VlWide<4>/*107:0*/ Top__DOT__decodeIssue__DOT__tempPayload2;
        VlWide<4>/*107:0*/ Top__DOT__decodeIssue__DOT__tempPayload1;
        VlWide<4>/*107:0*/ Top__DOT__decodeIssue__DOT__finalUpperPayload;
        VlWide<4>/*104:0*/ Top__DOT__decodeIssue__DOT__finalLowerPayload;
        VlUnpacked<VlWide<3>/*77:0*/, 8> Top__DOT__memoryQueue__DOT__queueEntry;
        VlUnpacked<IData/*31:0*/, 1024> Top__DOT__placeholderDMEM__DOT__memory;
        VlUnpacked<VlWide<3>/*74:0*/, 16> Top__DOT__reorderBuffer__DOT__reorderBuffer;
        VlUnpacked<CData/*3:0*/, 16> Top__DOT__reorderBuffer__DOT__sortGrid;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 3>, 16> Top__DOT__reorderBuffer__DOT__maskGrid;
        VlUnpacked<CData/*6:0*/, 32> Top__DOT__registerStatusTable__DOT__registerStatusTable;
        VlUnpacked<IData/*31:0*/, 32> Top__DOT__registerFile__DOT__registerFile;
        VlUnpacked<VlWide<4>/*127:0*/, 256> Top__DOT__instructionMemory__DOT__memory;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

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
