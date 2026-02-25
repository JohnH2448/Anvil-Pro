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
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(redirect,0,0);
    VL_IN8(assert1,0,0);
    VL_IN8(assert2,0,0);
    CData/*0:0*/ Top__DOT__instructionConsumed1;
    CData/*0:0*/ Top__DOT__instructionConsumed2;
    CData/*0:0*/ Top__DOT__decodeIssue__DOT__instructionsValid;
    CData/*0:0*/ Top__DOT__decodeIssue__DOT__postRedirectCounter;
    CData/*0:0*/ Top__DOT__decodeIssue__DOT__internalBadData;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(instruction1,31,0);
    VL_OUT(instruction2,31,0);
    VlWide<4>/*127:0*/ Top__DOT__lowFetchData;
    VlWide<4>/*127:0*/ Top__DOT__highFetchData;
    IData/*31:0*/ Top__DOT__programCounter;
    IData/*31:0*/ Top__DOT__requestPC1;
    IData/*31:0*/ Top__DOT__requestPC2;
    IData/*31:0*/ Top__DOT__walkingWindow__DOT__lastLowWindow;
    IData/*31:0*/ Top__DOT__walkingWindow__DOT__lastHighWindow;
    IData/*31:0*/ Top__DOT__decodeIssue__DOT__IR1;
    IData/*31:0*/ Top__DOT__decodeIssue__DOT__IR2;
    IData/*31:0*/ Top__DOT__decodeIssue__DOT__PC1;
    IData/*31:0*/ Top__DOT__decodeIssue__DOT__PC2;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<VlWide<4>/*127:0*/, 256> Top__DOT__instructionMemory__DOT__memory;
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
