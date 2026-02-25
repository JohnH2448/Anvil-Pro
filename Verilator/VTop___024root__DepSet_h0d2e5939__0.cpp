// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

extern const VlUnpacked<CData/*1:0*/, 16> VTop__ConstPool__TABLE_ha58aa0c9_0;
extern const VlUnpacked<CData/*0:0*/, 16> VTop__ConstPool__TABLE_h0ada650b_0;
extern const VlUnpacked<CData/*0:0*/, 16> VTop__ConstPool__TABLE_h2f85f368_0;

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__internalBadData) 
                     << 3U) | (((IData)(vlSelf->assert2) 
                                << 2U) | (((IData)(vlSelf->assert1) 
                                           << 1U) | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid))));
    if ((1U & VTop__ConstPool__TABLE_ha58aa0c9_0[__Vtableidx1])) {
        vlSelf->Top__DOT__instructionConsumed1 = VTop__ConstPool__TABLE_h0ada650b_0
            [__Vtableidx1];
    }
    if ((2U & VTop__ConstPool__TABLE_ha58aa0c9_0[__Vtableidx1])) {
        vlSelf->Top__DOT__instructionConsumed2 = VTop__ConstPool__TABLE_h2f85f368_0
            [__Vtableidx1];
    }
    if (vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid) {
        if (((IData)(vlSelf->Top__DOT__instructionConsumed1) 
             & (IData)(vlSelf->Top__DOT__instructionConsumed2))) {
            vlSelf->Top__DOT__requestPC1 = ((IData)(8U) 
                                            + vlSelf->Top__DOT__programCounter);
            vlSelf->Top__DOT__requestPC2 = ((IData)(0xcU) 
                                            + vlSelf->Top__DOT__programCounter);
        } else if (vlSelf->Top__DOT__instructionConsumed1) {
            vlSelf->Top__DOT__requestPC1 = ((IData)(4U) 
                                            + vlSelf->Top__DOT__programCounter);
            vlSelf->Top__DOT__requestPC2 = ((IData)(8U) 
                                            + vlSelf->Top__DOT__programCounter);
        } else {
            vlSelf->Top__DOT__requestPC1 = vlSelf->Top__DOT__programCounter;
            vlSelf->Top__DOT__requestPC2 = ((IData)(4U) 
                                            + vlSelf->Top__DOT__programCounter);
        }
    } else {
        vlSelf->Top__DOT__requestPC1 = vlSelf->Top__DOT__programCounter;
        vlSelf->Top__DOT__requestPC2 = ((IData)(4U) 
                                        + vlSelf->Top__DOT__programCounter);
    }
    vlSelf->instruction1 = 0xdeadbeefU;
    if (((vlSelf->Top__DOT__requestPC1 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow 
                                                  >> 4U))) {
        vlSelf->instruction1 = ((8U & vlSelf->Top__DOT__requestPC1)
                                 ? ((4U & vlSelf->Top__DOT__requestPC1)
                                     ? vlSelf->Top__DOT__lowFetchData[3U]
                                     : vlSelf->Top__DOT__lowFetchData[2U])
                                 : ((4U & vlSelf->Top__DOT__requestPC1)
                                     ? vlSelf->Top__DOT__lowFetchData[1U]
                                     : vlSelf->Top__DOT__lowFetchData[0U]));
    }
    if (((vlSelf->Top__DOT__requestPC1 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow 
                                                  >> 4U))) {
        vlSelf->instruction1 = ((8U & vlSelf->Top__DOT__requestPC1)
                                 ? ((4U & vlSelf->Top__DOT__requestPC1)
                                     ? vlSelf->Top__DOT__highFetchData[3U]
                                     : vlSelf->Top__DOT__highFetchData[2U])
                                 : ((4U & vlSelf->Top__DOT__requestPC1)
                                     ? vlSelf->Top__DOT__highFetchData[1U]
                                     : vlSelf->Top__DOT__highFetchData[0U]));
    }
    vlSelf->instruction2 = 0xdeadbeefU;
    if (((vlSelf->Top__DOT__requestPC2 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow 
                                                  >> 4U))) {
        vlSelf->instruction2 = ((8U & vlSelf->Top__DOT__requestPC2)
                                 ? ((4U & vlSelf->Top__DOT__requestPC2)
                                     ? vlSelf->Top__DOT__lowFetchData[3U]
                                     : vlSelf->Top__DOT__lowFetchData[2U])
                                 : ((4U & vlSelf->Top__DOT__requestPC2)
                                     ? vlSelf->Top__DOT__lowFetchData[1U]
                                     : vlSelf->Top__DOT__lowFetchData[0U]));
    }
    if (((vlSelf->Top__DOT__requestPC2 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow 
                                                  >> 4U))) {
        vlSelf->instruction2 = ((8U & vlSelf->Top__DOT__requestPC2)
                                 ? ((4U & vlSelf->Top__DOT__requestPC2)
                                     ? vlSelf->Top__DOT__highFetchData[3U]
                                     : vlSelf->Top__DOT__highFetchData[2U])
                                 : ((4U & vlSelf->Top__DOT__requestPC2)
                                     ? vlSelf->Top__DOT__highFetchData[1U]
                                     : vlSelf->Top__DOT__highFetchData[0U]));
    }
}

void VTop___024root___eval_ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VTop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VTop___024root___eval_triggers__ico(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VTop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VTop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*31:0*/ __Vdly__Top__DOT__programCounter;
    __Vdly__Top__DOT__programCounter = 0;
    CData/*0:0*/ __Vdly__Top__DOT__decodeIssue__DOT__postRedirectCounter;
    __Vdly__Top__DOT__decodeIssue__DOT__postRedirectCounter = 0;
    // Body
    __Vdly__Top__DOT__programCounter = vlSelf->Top__DOT__programCounter;
    __Vdly__Top__DOT__decodeIssue__DOT__postRedirectCounter 
        = vlSelf->Top__DOT__decodeIssue__DOT__postRedirectCounter;
    if (VL_UNLIKELY(((IData)(vlSelf->Top__DOT__instructionConsumed1) 
                     & (IData)(vlSelf->Top__DOT__instructionConsumed2)))) {
        VL_WRITEF("Issued %x, PC: %x\nIssued %x, PC: %x\n",
                  32,vlSelf->Top__DOT__decodeIssue__DOT__IR1,
                  32,vlSelf->Top__DOT__decodeIssue__DOT__PC1,
                  32,vlSelf->Top__DOT__decodeIssue__DOT__IR2,
                  32,vlSelf->Top__DOT__decodeIssue__DOT__PC2);
    } else if (VL_UNLIKELY(vlSelf->Top__DOT__instructionConsumed1)) {
        VL_WRITEF("Issued %x, PC: %x\n",32,vlSelf->Top__DOT__decodeIssue__DOT__IR1,
                  32,vlSelf->Top__DOT__decodeIssue__DOT__PC1);
    }
    if (((IData)(vlSelf->reset) | (IData)(vlSelf->redirect))) {
        __Vdly__Top__DOT__programCounter = ((IData)(vlSelf->reset)
                                             ? 0U : 0x28U);
        vlSelf->Top__DOT__highFetchData[0U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(vlSelf->reset) ? 0x10U
                         : 0x38U) >> 4U))][0U];
        vlSelf->Top__DOT__highFetchData[1U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(vlSelf->reset) ? 0x10U
                         : 0x38U) >> 4U))][1U];
        vlSelf->Top__DOT__highFetchData[2U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(vlSelf->reset) ? 0x10U
                         : 0x38U) >> 4U))][2U];
        vlSelf->Top__DOT__highFetchData[3U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(vlSelf->reset) ? 0x10U
                         : 0x38U) >> 4U))][3U];
        vlSelf->Top__DOT__lowFetchData[0U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(vlSelf->reset) ? 0U
                         : 0x28U) >> 4U))][0U];
        vlSelf->Top__DOT__lowFetchData[1U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(vlSelf->reset) ? 0U
                         : 0x28U) >> 4U))][1U];
        vlSelf->Top__DOT__lowFetchData[2U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(vlSelf->reset) ? 0U
                         : 0x28U) >> 4U))][2U];
        vlSelf->Top__DOT__lowFetchData[3U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(vlSelf->reset) ? 0U
                         : 0x28U) >> 4U))][3U];
        vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid = 0U;
        __Vdly__Top__DOT__decodeIssue__DOT__postRedirectCounter = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__IR1 = 0xdeadbeefU;
        vlSelf->Top__DOT__decodeIssue__DOT__IR2 = 0xdeadbeefU;
    } else {
        if (((IData)(vlSelf->Top__DOT__instructionConsumed1) 
             & (IData)(vlSelf->Top__DOT__instructionConsumed2))) {
            __Vdly__Top__DOT__programCounter = ((IData)(8U) 
                                                + vlSelf->Top__DOT__programCounter);
        } else if (vlSelf->Top__DOT__instructionConsumed1) {
            __Vdly__Top__DOT__programCounter = ((IData)(4U) 
                                                + vlSelf->Top__DOT__programCounter);
        }
        vlSelf->Top__DOT__highFetchData[0U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(0x10U) + (0xfffffff0U 
                                          & vlSelf->Top__DOT__programCounter)) 
                       >> 4U))][0U];
        vlSelf->Top__DOT__highFetchData[1U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(0x10U) + (0xfffffff0U 
                                          & vlSelf->Top__DOT__programCounter)) 
                       >> 4U))][1U];
        vlSelf->Top__DOT__highFetchData[2U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(0x10U) + (0xfffffff0U 
                                          & vlSelf->Top__DOT__programCounter)) 
                       >> 4U))][2U];
        vlSelf->Top__DOT__highFetchData[3U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (((IData)(0x10U) + (0xfffffff0U 
                                          & vlSelf->Top__DOT__programCounter)) 
                       >> 4U))][3U];
        vlSelf->Top__DOT__lowFetchData[0U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (vlSelf->Top__DOT__programCounter 
                       >> 4U))][0U];
        vlSelf->Top__DOT__lowFetchData[1U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (vlSelf->Top__DOT__programCounter 
                       >> 4U))][1U];
        vlSelf->Top__DOT__lowFetchData[2U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (vlSelf->Top__DOT__programCounter 
                       >> 4U))][2U];
        vlSelf->Top__DOT__lowFetchData[3U] = vlSelf->Top__DOT__instructionMemory__DOT__memory
            [(0xffU & (vlSelf->Top__DOT__programCounter 
                       >> 4U))][3U];
        if (vlSelf->Top__DOT__decodeIssue__DOT__postRedirectCounter) {
            vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                = vlSelf->instruction1;
            vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                = vlSelf->instruction2;
            vlSelf->Top__DOT__decodeIssue__DOT__PC1 
                = vlSelf->Top__DOT__requestPC1;
            vlSelf->Top__DOT__decodeIssue__DOT__PC2 
                = vlSelf->Top__DOT__requestPC2;
            vlSelf->Top__DOT__decodeIssue__DOT__internalBadData 
                = (((vlSelf->Top__DOT__requestPC2 >> 4U) 
                    != (vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow 
                        >> 4U)) & ((vlSelf->Top__DOT__requestPC2 
                                    >> 4U) != (vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow 
                                               >> 4U)));
        } else {
            __Vdly__Top__DOT__decodeIssue__DOT__postRedirectCounter 
                = (1U & ((IData)(1U) + (IData)(vlSelf->Top__DOT__decodeIssue__DOT__postRedirectCounter)));
        }
    }
    vlSelf->Top__DOT__decodeIssue__DOT__postRedirectCounter 
        = __Vdly__Top__DOT__decodeIssue__DOT__postRedirectCounter;
    __Vtableidx1 = (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__internalBadData) 
                     << 3U) | (((IData)(vlSelf->assert2) 
                                << 2U) | (((IData)(vlSelf->assert1) 
                                           << 1U) | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid))));
    if ((1U & VTop__ConstPool__TABLE_ha58aa0c9_0[__Vtableidx1])) {
        vlSelf->Top__DOT__instructionConsumed1 = VTop__ConstPool__TABLE_h0ada650b_0
            [__Vtableidx1];
    }
    if ((2U & VTop__ConstPool__TABLE_ha58aa0c9_0[__Vtableidx1])) {
        vlSelf->Top__DOT__instructionConsumed2 = VTop__ConstPool__TABLE_h2f85f368_0
            [__Vtableidx1];
    }
    if (vlSelf->reset) {
        vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow = 0x10U;
        vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow = 0U;
    } else if (vlSelf->redirect) {
        vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow = 0x30U;
        vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow = 0x20U;
    } else {
        vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow 
            = ((IData)(0x10U) + (0xfffffff0U & vlSelf->Top__DOT__programCounter));
        vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow 
            = (0xfffffff0U & vlSelf->Top__DOT__programCounter);
    }
    vlSelf->Top__DOT__programCounter = __Vdly__Top__DOT__programCounter;
    if (vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid) {
        if (((IData)(vlSelf->Top__DOT__instructionConsumed1) 
             & (IData)(vlSelf->Top__DOT__instructionConsumed2))) {
            vlSelf->Top__DOT__requestPC1 = ((IData)(8U) 
                                            + vlSelf->Top__DOT__programCounter);
            vlSelf->Top__DOT__requestPC2 = ((IData)(0xcU) 
                                            + vlSelf->Top__DOT__programCounter);
        } else if (vlSelf->Top__DOT__instructionConsumed1) {
            vlSelf->Top__DOT__requestPC1 = ((IData)(4U) 
                                            + vlSelf->Top__DOT__programCounter);
            vlSelf->Top__DOT__requestPC2 = ((IData)(8U) 
                                            + vlSelf->Top__DOT__programCounter);
        } else {
            vlSelf->Top__DOT__requestPC1 = vlSelf->Top__DOT__programCounter;
            vlSelf->Top__DOT__requestPC2 = ((IData)(4U) 
                                            + vlSelf->Top__DOT__programCounter);
        }
    } else {
        vlSelf->Top__DOT__requestPC1 = vlSelf->Top__DOT__programCounter;
        vlSelf->Top__DOT__requestPC2 = ((IData)(4U) 
                                        + vlSelf->Top__DOT__programCounter);
    }
    vlSelf->instruction1 = 0xdeadbeefU;
    if (((vlSelf->Top__DOT__requestPC1 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow 
                                                  >> 4U))) {
        vlSelf->instruction1 = ((8U & vlSelf->Top__DOT__requestPC1)
                                 ? ((4U & vlSelf->Top__DOT__requestPC1)
                                     ? vlSelf->Top__DOT__lowFetchData[3U]
                                     : vlSelf->Top__DOT__lowFetchData[2U])
                                 : ((4U & vlSelf->Top__DOT__requestPC1)
                                     ? vlSelf->Top__DOT__lowFetchData[1U]
                                     : vlSelf->Top__DOT__lowFetchData[0U]));
    }
    if (((vlSelf->Top__DOT__requestPC1 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow 
                                                  >> 4U))) {
        vlSelf->instruction1 = ((8U & vlSelf->Top__DOT__requestPC1)
                                 ? ((4U & vlSelf->Top__DOT__requestPC1)
                                     ? vlSelf->Top__DOT__highFetchData[3U]
                                     : vlSelf->Top__DOT__highFetchData[2U])
                                 : ((4U & vlSelf->Top__DOT__requestPC1)
                                     ? vlSelf->Top__DOT__highFetchData[1U]
                                     : vlSelf->Top__DOT__highFetchData[0U]));
    }
    vlSelf->instruction2 = 0xdeadbeefU;
    if (((vlSelf->Top__DOT__requestPC2 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow 
                                                  >> 4U))) {
        vlSelf->instruction2 = ((8U & vlSelf->Top__DOT__requestPC2)
                                 ? ((4U & vlSelf->Top__DOT__requestPC2)
                                     ? vlSelf->Top__DOT__lowFetchData[3U]
                                     : vlSelf->Top__DOT__lowFetchData[2U])
                                 : ((4U & vlSelf->Top__DOT__requestPC2)
                                     ? vlSelf->Top__DOT__lowFetchData[1U]
                                     : vlSelf->Top__DOT__lowFetchData[0U]));
    }
    if (((vlSelf->Top__DOT__requestPC2 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow 
                                                  >> 4U))) {
        vlSelf->instruction2 = ((8U & vlSelf->Top__DOT__requestPC2)
                                 ? ((4U & vlSelf->Top__DOT__requestPC2)
                                     ? vlSelf->Top__DOT__highFetchData[3U]
                                     : vlSelf->Top__DOT__highFetchData[2U])
                                 : ((4U & vlSelf->Top__DOT__requestPC2)
                                     ? vlSelf->Top__DOT__highFetchData[1U]
                                     : vlSelf->Top__DOT__highFetchData[0U]));
    }
}

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VTop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VTop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VTop___024root___eval_phase__nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VTop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("Test/Subsystems/FetchTest.sv", 6, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VTop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("Test/Subsystems/FetchTest.sv", 6, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("Test/Subsystems/FetchTest.sv", 6, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VTop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VTop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->redirect & 0xfeU))) {
        Verilated::overWidthError("redirect");}
    if (VL_UNLIKELY((vlSelf->assert1 & 0xfeU))) {
        Verilated::overWidthError("assert1");}
    if (VL_UNLIKELY((vlSelf->assert2 & 0xfeU))) {
        Verilated::overWidthError("assert2");}
}
#endif  // VL_DEBUG
