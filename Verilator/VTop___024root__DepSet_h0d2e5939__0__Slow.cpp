// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___eval_static(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_static\n"); );
}

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    // Body
    VTop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = vlSelf->clock;
}

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<7>/*223:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x696f6e73U;
    __Vtemp_1[2U] = 0x72756374U;
    __Vtemp_1[3U] = 0x496e7374U;
    __Vtemp_1[4U] = 0x6f72792fU;
    __Vtemp_1[5U] = 0x2f4d656dU;
    __Vtemp_1[6U] = 0x436f7265U;
    VL_READMEM_N(true, 128, 256, 0, VL_CVT_PACK_STR_NW(7, __Vtemp_1)
                 ,  &(vlSelf->Top__DOT__instructionMemory__DOT__memory)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void VTop___024root___eval_final(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VTop___024root___eval_phase__stl(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("Test/Subsystems/PipelineTest.sv", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VTop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ Top__DOT__upperROBData1;
    Top__DOT__upperROBData1 = 0;
    IData/*31:0*/ Top__DOT__upperROBData2;
    Top__DOT__upperROBData2 = 0;
    IData/*31:0*/ Top__DOT__lowerROBData1;
    Top__DOT__lowerROBData1 = 0;
    IData/*31:0*/ Top__DOT__lowerROBData2;
    Top__DOT__lowerROBData2 = 0;
    CData/*0:0*/ Top__DOT__upperInFlightLoad1;
    Top__DOT__upperInFlightLoad1 = 0;
    CData/*0:0*/ Top__DOT__upperInFlightLoad2;
    Top__DOT__upperInFlightLoad2 = 0;
    CData/*0:0*/ Top__DOT__lowerInFlightLoad1;
    Top__DOT__lowerInFlightLoad1 = 0;
    CData/*0:0*/ Top__DOT__lowerInFlightLoad2;
    Top__DOT__lowerInFlightLoad2 = 0;
    CData/*0:0*/ Top__DOT__destRegLoad1;
    Top__DOT__destRegLoad1 = 0;
    CData/*0:0*/ Top__DOT__destRegLoad2;
    Top__DOT__destRegLoad2 = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__redirectNextTailPointer;
    Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__ageVector;
    Top__DOT__reorderBuffer__DOT__ageVector = 0;
    CData/*0:0*/ Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 = 0;
    IData/*31:0*/ Top__DOT__operandSelect__DOT__upperOperand1;
    Top__DOT__operandSelect__DOT__upperOperand1 = 0;
    IData/*31:0*/ Top__DOT__operandSelect__DOT__upperOperand2;
    Top__DOT__operandSelect__DOT__upperOperand2 = 0;
    IData/*31:0*/ Top__DOT__operandSelect__DOT__lowerOperand1;
    Top__DOT__operandSelect__DOT__lowerOperand1 = 0;
    IData/*31:0*/ Top__DOT__operandSelect__DOT__lowerOperand2;
    Top__DOT__operandSelect__DOT__lowerOperand2 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__redirectVector1;
    Top__DOT__execute__DOT__redirectVector1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__redirectVector2;
    Top__DOT__execute__DOT__redirectVector2 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT__illegal1;
    Top__DOT__execute__DOT__illegal1 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT__illegal2;
    Top__DOT__execute__DOT__illegal2 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0;
    Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0;
    Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0;
    Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0;
    Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0 = 0;
    CData/*0:0*/ Top__DOT__decodeIssue__DOT__illegal2;
    Top__DOT__decodeIssue__DOT__illegal2 = 0;
    CData/*0:0*/ Top__DOT__decodeIssue__DOT__illegal1;
    Top__DOT__decodeIssue__DOT__illegal1 = 0;
    // Body
    vlSelf->Top__DOT__resolvedInstruction1 = 0ULL;
    vlSelf->Top__DOT__resolvedInstruction2 = 0ULL;
    vlSelf->Top__DOT__triggerStore = 0U;
    if ((1U & (~ (((1U < (0x1fU & ((IData)(0x10U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
                   & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                      [0U][0U] | (0U == (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [0U][0U] 
                                                  >> 7U))))) 
                  & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                     [1U][0U] | (0U == (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                 [1U][0U] 
                                                 >> 7U)))))))) {
        if ((1U & (~ ((0U < (0x1fU & ((IData)(0x10U) 
                                      - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
                      & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                         [0U][0U] | (0U == (0x1fU & 
                                            (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                             [0U][0U] 
                                             >> 7U)))))))) {
            if (((0U < (0x1fU & ((IData)(0x10U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                    [0U][0U] >> 1U))) {
                vlSelf->Top__DOT__triggerStore = 1U;
            }
        }
    }
    vlSelf->Top__DOT__decodeIssue__DOT__reasonBadFetch = 0U;
    if ((0U != (vlSelf->Top__DOT__payload1[1U] >> 0x1bU))) {
        vlSelf->Top__DOT__upperSource1Status = ((1U 
                                                 & (IData)(vlSelf->Top__DOT__upperSource1Status)) 
                                                | ((0x40U 
                                                    & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (vlSelf->Top__DOT__payload1[1U] 
                                                        >> 0x1bU)] 
                                                       << 5U)) 
                                                   | (0x3eU 
                                                      & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                         [
                                                         (vlSelf->Top__DOT__payload1[1U] 
                                                          >> 0x1bU)] 
                                                         >> 1U))));
        vlSelf->Top__DOT__upperSource1Status = ((0x7eU 
                                                 & (IData)(vlSelf->Top__DOT__upperSource1Status)) 
                                                | (1U 
                                                   & vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [
                                                   (vlSelf->Top__DOT__payload1[1U] 
                                                    >> 0x1bU)]));
    } else {
        vlSelf->Top__DOT__upperSource1Status = (0x40U 
                                                | (IData)(vlSelf->Top__DOT__upperSource1Status));
        vlSelf->Top__DOT__upperSource1Status = (1U 
                                                | (IData)(vlSelf->Top__DOT__upperSource1Status));
    }
    if ((0U != (0x1fU & (vlSelf->Top__DOT__payload2[1U] 
                         >> 0x18U)))) {
        vlSelf->Top__DOT__lowerSource1Status = ((1U 
                                                 & (IData)(vlSelf->Top__DOT__lowerSource1Status)) 
                                                | ((0x40U 
                                                    & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__payload2[1U] 
                                                           >> 0x18U))] 
                                                       << 5U)) 
                                                   | (0x3eU 
                                                      & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                         [
                                                         (0x1fU 
                                                          & (vlSelf->Top__DOT__payload2[1U] 
                                                             >> 0x18U))] 
                                                         >> 1U))));
        vlSelf->Top__DOT__lowerSource1Status = ((0x7eU 
                                                 & (IData)(vlSelf->Top__DOT__lowerSource1Status)) 
                                                | (1U 
                                                   & vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT__payload2[1U] 
                                                       >> 0x18U))]));
    } else {
        vlSelf->Top__DOT__lowerSource1Status = (0x40U 
                                                | (IData)(vlSelf->Top__DOT__lowerSource1Status));
        vlSelf->Top__DOT__lowerSource1Status = (1U 
                                                | (IData)(vlSelf->Top__DOT__lowerSource1Status));
    }
    if ((0U != (0x1fU & vlSelf->Top__DOT__payload1[2U]))) {
        vlSelf->Top__DOT__upperSource2Status = ((1U 
                                                 & (IData)(vlSelf->Top__DOT__upperSource2Status)) 
                                                | ((0x40U 
                                                    & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & vlSelf->Top__DOT__payload1[2U])] 
                                                       << 5U)) 
                                                   | (0x3eU 
                                                      & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                         [
                                                         (0x1fU 
                                                          & vlSelf->Top__DOT__payload1[2U])] 
                                                         >> 1U))));
        vlSelf->Top__DOT__upperSource2Status = ((0x7eU 
                                                 & (IData)(vlSelf->Top__DOT__upperSource2Status)) 
                                                | (1U 
                                                   & vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [
                                                   (0x1fU 
                                                    & vlSelf->Top__DOT__payload1[2U])]));
    } else {
        vlSelf->Top__DOT__upperSource2Status = (0x40U 
                                                | (IData)(vlSelf->Top__DOT__upperSource2Status));
        vlSelf->Top__DOT__upperSource2Status = (1U 
                                                | (IData)(vlSelf->Top__DOT__upperSource2Status));
    }
    if ((0U != (0x1fU & ((vlSelf->Top__DOT__payload2[2U] 
                          << 3U) | (vlSelf->Top__DOT__payload2[1U] 
                                    >> 0x1dU))))) {
        vlSelf->Top__DOT__lowerSource2Status = ((1U 
                                                 & (IData)(vlSelf->Top__DOT__lowerSource2Status)) 
                                                | ((0x40U 
                                                    & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & ((vlSelf->Top__DOT__payload2[2U] 
                                                            << 3U) 
                                                           | (vlSelf->Top__DOT__payload2[1U] 
                                                              >> 0x1dU)))] 
                                                       << 5U)) 
                                                   | (0x3eU 
                                                      & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                         [
                                                         (0x1fU 
                                                          & ((vlSelf->Top__DOT__payload2[2U] 
                                                              << 3U) 
                                                             | (vlSelf->Top__DOT__payload2[1U] 
                                                                >> 0x1dU)))] 
                                                         >> 1U))));
        vlSelf->Top__DOT__lowerSource2Status = ((0x7eU 
                                                 & (IData)(vlSelf->Top__DOT__lowerSource2Status)) 
                                                | (1U 
                                                   & vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [
                                                   (0x1fU 
                                                    & ((vlSelf->Top__DOT__payload2[2U] 
                                                        << 3U) 
                                                       | (vlSelf->Top__DOT__payload2[1U] 
                                                          >> 0x1dU)))]));
    } else {
        vlSelf->Top__DOT__lowerSource2Status = (0x40U 
                                                | (IData)(vlSelf->Top__DOT__lowerSource2Status));
        vlSelf->Top__DOT__lowerSource2Status = (1U 
                                                | (IData)(vlSelf->Top__DOT__lowerSource2Status));
    }
    vlSelf->Top__DOT__reorderBuffer__DOT__retireCount = 0U;
    if ((((1U < (0x1fU & ((IData)(0x10U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
          & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
             [0U][0U] | (0U == (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                         [0U][0U] >> 7U))))) 
         & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
            [1U][0U] | (0U == (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [1U][0U] >> 7U)))))) {
        if (((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                              [0U][0U] >> 7U))) & (
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                       [0U][0U] 
                                                       >> 7U)) 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                       [1U][0U] 
                                                       >> 7U))))) {
            vlSelf->Top__DOT__resolvedInstruction1 
                = (1ULL | (0x7fffffffffeULL & (((QData)((IData)(
                                                                vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                [1U][1U])) 
                                                << 0x1fU) 
                                               | (0x7ffffffffffffffeULL 
                                                  & ((QData)((IData)(
                                                                     vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                     [1U][0U])) 
                                                     >> 1U)))));
        } else if ((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0U][0U] >> 7U)))) {
            vlSelf->Top__DOT__resolvedInstruction1 
                = (1ULL | (0x7fffffffffeULL & (((QData)((IData)(
                                                                vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                [0U][1U])) 
                                                << 0x1fU) 
                                               | (0x7ffffffffffffffeULL 
                                                  & ((QData)((IData)(
                                                                     vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                     [0U][0U])) 
                                                     >> 1U)))));
        }
        if ((1U & (~ ((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                       [0U][0U] >> 7U))) 
                      & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [0U][0U] >> 7U)) 
                         == (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [1U][0U] >> 7U))))))) {
            if ((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                 [1U][0U] >> 7U)))) {
                vlSelf->Top__DOT__resolvedInstruction2 
                    = (1ULL | (0x7fffffffffeULL & (
                                                   ((QData)((IData)(
                                                                    vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                    [1U][1U])) 
                                                    << 0x1fU) 
                                                   | (0x7ffffffffffffffeULL 
                                                      & ((QData)((IData)(
                                                                         vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                         [1U][0U])) 
                                                         >> 1U)))));
            }
        }
        vlSelf->Top__DOT__reorderBuffer__DOT__retireCount = 2U;
    } else if (((0U < (0x1fU & ((IData)(0x10U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
                & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                   [0U][0U] | (0U == (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                               [0U][0U] 
                                               >> 7U)))))) {
        if ((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [0U][0U] >> 7U)))) {
            vlSelf->Top__DOT__resolvedInstruction1 
                = (1ULL | (0x7fffffffffeULL & (((QData)((IData)(
                                                                vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                [0U][1U])) 
                                                << 0x1fU) 
                                               | (0x7ffffffffffffffeULL 
                                                  & ((QData)((IData)(
                                                                     vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                     [0U][0U])) 
                                                     >> 1U)))));
        }
        vlSelf->Top__DOT__reorderBuffer__DOT__retireCount = 1U;
    }
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[3U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
        = ((0x1fU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
           | (vlSelf->Top__DOT__decodeIssue__DOT__PC2 
              << 5U));
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[3U] 
        = (vlSelf->Top__DOT__decodeIssue__DOT__PC2 
           >> 0x1bU);
    Top__DOT__decodeIssue__DOT__illegal2 = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 = 0U;
    if ((0x40U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((0x20U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((1U & (~ vlSelf->Top__DOT__decodeIssue__DOT__IR2))) {
                        Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                            vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                                = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                            >> 7U));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                = (0x200000U | (0xffcfffffU 
                                                & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                = (0x40U | (0xffffff3fU 
                                            & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                                   | (0xf0000000U & 
                                      (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                       << 7U)));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                                = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                                   | (0x7ffffffU & 
                                      ((0x7ff8000U 
                                        & ((- (IData)(
                                                      (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                       >> 0x1fU))) 
                                           << 0xfU)) 
                                       | ((0x7f80U 
                                           & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                              >> 5U)) 
                                          | ((0x40U 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                 >> 0xeU)) 
                                             | (0x3fU 
                                                & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                   >> 0x19U)))))));
                        } else {
                            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                        }
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                            = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                               | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                 << 0xcU)));
                        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                            = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                        >> 7U));
                        if ((0U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                          >> 0xcU)))) {
                            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                        }
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x100000U | (0xffcfffffU 
                                            & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x80U | (0xffffff3fU 
                                        & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                               | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                 << 7U)));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                            = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                               | (0x7ffffffU & ((0x7ffff80U 
                                                 & ((- (IData)(
                                                               (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                                >> 0x1fU))) 
                                                    << 7U)) 
                                                | (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                   >> 0x19U))));
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                        = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                           | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                             << 0xcU)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                        = ((0xffffffe0U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                           | (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                       >> 0x14U)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0xffcfffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                           | (0xf0000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                             << 0x14U)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                        = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                           | (0x7ffffffU & ((0x7ffff00U 
                                             & ((- (IData)(
                                                           (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                            >> 0x1fU))) 
                                                << 8U)) 
                                            | ((0x80U 
                                                & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                   >> 0x18U)) 
                                               | ((0x40U 
                                                   & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                      >> 1U)) 
                                                  | (0x3fU 
                                                     & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                        >> 0x19U)))))));
                    if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = ((0xffff8fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                               | (((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                    ? ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                        ? 6U : 5U) : 
                                   ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                     ? 4U : 3U)) << 0xcU));
                    } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = ((0xffff8fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                               | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                    ? 2U : 1U) << 0xcU));
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else if ((0x20U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                            = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                        >> 7U));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x300000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                            = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                               | (0x7ffff80U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 5U)));
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                        = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                    >> 7U));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                        = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                           | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                             << 0xcU)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                        = ((0xffffffe0U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                           | (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                       >> 0x14U)));
                    if (((((((((0U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0xcU)))) 
                               | (0x100U == ((0x3f8U 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                 >> 0x16U)) 
                                             | (7U 
                                                & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                   >> 0xcU))))) 
                              | (7U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                   >> 0x16U)) 
                                        | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                 >> 0xcU))))) 
                             | (6U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0xcU))))) 
                            | (4U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                 >> 0x16U)) 
                                      | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                               >> 0xcU))))) 
                           | (1U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0x16U)) 
                                     | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                              >> 0xcU))))) 
                          | (5U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                               >> 0x16U)) 
                                    | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                             >> 0xcU))))) 
                         | (0x105U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0xcU)))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = ((0xfffff0ffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                               | (((0U == ((0x3f8U 
                                            & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                               >> 0xcU))))
                                    ? 0U : ((0x100U 
                                             == ((0x3f8U 
                                                  & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                       >> 0xcU))))
                                             ? 1U : 
                                            ((7U == 
                                              ((0x3f8U 
                                                & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                   >> 0x16U)) 
                                               | (7U 
                                                  & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                     >> 0xcU))))
                                              ? 2U : 
                                             ((6U == 
                                               ((0x3f8U 
                                                 & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                    >> 0x16U)) 
                                                | (7U 
                                                   & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                      >> 0xcU))))
                                               ? 3U
                                               : ((4U 
                                                   == 
                                                   ((0x3f8U 
                                                     & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                        >> 0x16U)) 
                                                    | (7U 
                                                       & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                          >> 0xcU))))
                                                   ? 4U
                                                   : 
                                                  ((1U 
                                                    == 
                                                    ((0x3f8U 
                                                      & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                         >> 0x16U)) 
                                                     | (7U 
                                                        & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                           >> 0xcU))))
                                                    ? 5U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     ((0x3f8U 
                                                       & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                          >> 0x16U)) 
                                                      | (7U 
                                                         & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                            >> 0xcU))))
                                                     ? 6U
                                                     : 7U))))))) 
                                  << 8U));
                    } else if ((2U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0xcU))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x800U | (0xfffff0ffU 
                                         & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    } else if ((3U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0xcU))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x900U | (0xfffff0ffU 
                                         & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                    = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                       | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                         << 0xcU)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                    = ((0xffffffe0U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                       | (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                   >> 0x14U)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = (0x100000U | (0xffcfffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                       | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                         << 0x14U)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                    = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                       | (0x7ffffffU & ((0x7ffff80U 
                                         & ((- (IData)(
                                                       (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                        >> 0x1fU))) 
                                            << 7U)) 
                                        | (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                           >> 0x19U))));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = (0x80000U | (0xfff3ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                if ((0U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                  >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0xfffcffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                } else if ((1U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                         >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0x10000U | (0xfffcffffU 
                                       & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                } else if ((2U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                         >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0x30000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                } else {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                        = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                    >> 7U));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0x200000U | (0xffcfffffU 
                                        & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                        = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                           | (0x7ffff80U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                            >> 5U)));
                } else {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                    = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                >> 7U));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                    = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                       | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                         << 0xcU)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = (0x100000U | (0xffcfffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                       | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                         << 7U)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                    = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                       | (0x7ffffffU & ((0x7ffff80U 
                                         & ((- (IData)(
                                                       (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                        >> 0x1fU))) 
                                            << 7U)) 
                                        | (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                           >> 0x19U))));
                if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = ((0xfffff0ffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                               | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                    ? 2U : 3U) << 8U));
                    } else if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        if ((0U == (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                    >> 0x19U))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                = (0x600U | (0xfffff0ffU 
                                             & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                        } else if ((0x20U == (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                              >> 0x19U))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                = (0x700U | (0xfffff0ffU 
                                             & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                        } else {
                            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                        }
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x400U | (0xfffff0ffU 
                                         & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    }
                } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = ((0xfffff0ffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                           | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                ? 9U : 8U) << 8U));
                } else if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((0U == (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                >> 0x19U))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x500U | (0xfffff0ffU 
                                         & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0xfffff0ffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((0U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                      >> 0xcU)))) {
                        if ((1U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                          >> 0xcU)))) {
                            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                        }
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        Top__DOT__decodeIssue__DOT__illegal2 = 1U;
    } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                            >> 7U));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                   | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                     << 0xcU)));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                = (0x100000U | (0xffcfffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                   | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                     << 7U)));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                   | (0x7ffffffU & ((0x7ffff80U & (
                                                   (- (IData)(
                                                              (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                               >> 0x1fU))) 
                                                   << 7U)) 
                                    | (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                       >> 0x19U))));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                = (0x40000U | (0xfff3ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
            if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = ((0xfffc7fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                           | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                ? 2U : 0U) << 0xfU));
                }
            } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0x38000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = ((0xfffc7fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                       | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                            ? 3U : 1U) << 0xfU));
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else {
        Top__DOT__decodeIssue__DOT__illegal2 = 1U;
    }
    if (Top__DOT__decodeIssue__DOT__illegal2) {
        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
            = (0xfff3ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
    }
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[3U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
        = ((0x1fU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
           | (vlSelf->Top__DOT__decodeIssue__DOT__PC1 
              << 5U));
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[3U] 
        = (vlSelf->Top__DOT__decodeIssue__DOT__PC1 
           >> 0x1bU);
    Top__DOT__decodeIssue__DOT__illegal1 = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 = 0U;
    if ((0x40U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((0x20U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((1U & (~ vlSelf->Top__DOT__decodeIssue__DOT__IR1))) {
                        Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                            vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                                = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                            >> 7U));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                = (0x200000U | (0xffcfffffU 
                                                & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                = (0x40U | (0xffffff3fU 
                                            & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                                   | (0xf0000000U & 
                                      (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                       << 7U)));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                                = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                                   | (0x7ffffffU & 
                                      ((0x7ff8000U 
                                        & ((- (IData)(
                                                      (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                       >> 0x1fU))) 
                                           << 0xfU)) 
                                       | ((0x7f80U 
                                           & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                              >> 5U)) 
                                          | ((0x40U 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                 >> 0xeU)) 
                                             | (0x3fU 
                                                & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                   >> 0x19U)))))));
                        } else {
                            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                        }
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                            = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                               | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                 << 0xcU)));
                        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                            = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                        >> 7U));
                        if ((0U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                          >> 0xcU)))) {
                            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                        }
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x100000U | (0xffcfffffU 
                                            & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x80U | (0xffffff3fU 
                                        & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                               | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                 << 7U)));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                            = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                               | (0x7ffffffU & ((0x7ffff80U 
                                                 & ((- (IData)(
                                                               (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                                >> 0x1fU))) 
                                                    << 7U)) 
                                                | (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                   >> 0x19U))));
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                        = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                           | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                             << 0xcU)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                        = ((0xffffffe0U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                           | (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                       >> 0x14U)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0xffcfffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                           | (0xf0000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                             << 0x14U)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                        = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                           | (0x7ffffffU & ((0x7ffff00U 
                                             & ((- (IData)(
                                                           (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                            >> 0x1fU))) 
                                                << 8U)) 
                                            | ((0x80U 
                                                & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                   >> 0x18U)) 
                                               | ((0x40U 
                                                   & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                      >> 1U)) 
                                                  | (0x3fU 
                                                     & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                        >> 0x19U)))))));
                    if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = ((0xffff8fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                               | (((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                    ? ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                        ? 6U : 5U) : 
                                   ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                     ? 4U : 3U)) << 0xcU));
                    } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = ((0xffff8fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                               | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                    ? 2U : 1U) << 0xcU));
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else if ((0x20U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                            = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                        >> 7U));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x300000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                            = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                               | (0x7ffff80U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 5U)));
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                        = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                    >> 7U));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                        = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                           | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                             << 0xcU)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                        = ((0xffffffe0U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                           | (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                       >> 0x14U)));
                    if (((((((((0U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0xcU)))) 
                               | (0x100U == ((0x3f8U 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                 >> 0x16U)) 
                                             | (7U 
                                                & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                   >> 0xcU))))) 
                              | (7U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                   >> 0x16U)) 
                                        | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                 >> 0xcU))))) 
                             | (6U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0xcU))))) 
                            | (4U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                 >> 0x16U)) 
                                      | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                               >> 0xcU))))) 
                           | (1U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0x16U)) 
                                     | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                              >> 0xcU))))) 
                          | (5U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                               >> 0x16U)) 
                                    | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                             >> 0xcU))))) 
                         | (0x105U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0xcU)))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = ((0xfffff0ffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                               | (((0U == ((0x3f8U 
                                            & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                               >> 0x16U)) 
                                           | (7U & 
                                              (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                               >> 0xcU))))
                                    ? 0U : ((0x100U 
                                             == ((0x3f8U 
                                                  & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                       >> 0xcU))))
                                             ? 1U : 
                                            ((7U == 
                                              ((0x3f8U 
                                                & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                   >> 0x16U)) 
                                               | (7U 
                                                  & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                     >> 0xcU))))
                                              ? 2U : 
                                             ((6U == 
                                               ((0x3f8U 
                                                 & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                    >> 0x16U)) 
                                                | (7U 
                                                   & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                      >> 0xcU))))
                                               ? 3U
                                               : ((4U 
                                                   == 
                                                   ((0x3f8U 
                                                     & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                        >> 0x16U)) 
                                                    | (7U 
                                                       & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                          >> 0xcU))))
                                                   ? 4U
                                                   : 
                                                  ((1U 
                                                    == 
                                                    ((0x3f8U 
                                                      & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                         >> 0x16U)) 
                                                     | (7U 
                                                        & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                           >> 0xcU))))
                                                    ? 5U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     ((0x3f8U 
                                                       & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                          >> 0x16U)) 
                                                      | (7U 
                                                         & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                            >> 0xcU))))
                                                     ? 6U
                                                     : 7U))))))) 
                                  << 8U));
                    } else if ((2U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0xcU))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x800U | (0xfffff0ffU 
                                         & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    } else if ((3U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0xcU))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x900U | (0xfffff0ffU 
                                         & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                    = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                       | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                         << 0xcU)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                    = ((0xffffffe0U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                       | (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                   >> 0x14U)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = (0x100000U | (0xffcfffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                       | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                         << 0x14U)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                    = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                       | (0x7ffffffU & ((0x7ffff80U 
                                         & ((- (IData)(
                                                       (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                        >> 0x1fU))) 
                                            << 7U)) 
                                        | (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                           >> 0x19U))));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = (0x80000U | (0xfff3ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                if ((0U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                  >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0xfffcffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                } else if ((1U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                         >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0x10000U | (0xfffcffffU 
                                       & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                } else if ((2U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                         >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0x30000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                } else {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                        = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                    >> 7U));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0x200000U | (0xffcfffffU 
                                        & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                        = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                           | (0x7ffff80U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                            >> 5U)));
                } else {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                    = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                >> 7U));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                    = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                       | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                         << 0xcU)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = (0x100000U | (0xffcfffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                       | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                         << 7U)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                    = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                       | (0x7ffffffU & ((0x7ffff80U 
                                         & ((- (IData)(
                                                       (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                        >> 0x1fU))) 
                                            << 7U)) 
                                        | (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                           >> 0x19U))));
                if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = ((0xfffff0ffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                               | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                    ? 2U : 3U) << 8U));
                    } else if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        if ((0U == (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                    >> 0x19U))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                = (0x600U | (0xfffff0ffU 
                                             & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                        } else if ((0x20U == (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                              >> 0x19U))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                = (0x700U | (0xfffff0ffU 
                                             & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                        } else {
                            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                        }
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x400U | (0xfffff0ffU 
                                         & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    }
                } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = ((0xfffff0ffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                           | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                ? 9U : 8U) << 8U));
                } else if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((0U == (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                >> 0x19U))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x500U | (0xfffff0ffU 
                                         & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    } else {
                        Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0xfffff0ffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((0U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                      >> 0xcU)))) {
                        if ((1U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                          >> 0xcU)))) {
                            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                        }
                    }
                } else {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        Top__DOT__decodeIssue__DOT__illegal1 = 1U;
    } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                            >> 7U));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                   | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                     << 0xcU)));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                = (0x100000U | (0xffcfffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                = ((0x7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                   | (0xf8000000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                     << 7U)));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                = ((0xf8000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                   | (0x7ffffffU & ((0x7ffff80U & (
                                                   (- (IData)(
                                                              (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                               >> 0x1fU))) 
                                                   << 7U)) 
                                    | (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                       >> 0x19U))));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                = (0x40000U | (0xfff3ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
            if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = ((0xfffc7fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                           | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                ? 2U : 0U) << 0xfU));
                }
            } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0x38000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = ((0xfffc7fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                       | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                            ? 3U : 1U) << 0xfU));
            }
        } else {
            Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else {
        Top__DOT__decodeIssue__DOT__illegal1 = 1U;
    }
    if (Top__DOT__decodeIssue__DOT__illegal1) {
        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
            = (0xfff3ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
    }
    vlSelf->Top__DOT__execute__DOT__upperOperand1 = 
        ((vlSelf->Top__DOT__exPayload1[3U] << 7U) | 
         (vlSelf->Top__DOT__exPayload1[2U] >> 0x19U));
    vlSelf->Top__DOT__execute__DOT__upperOperand2 = 
        ((vlSelf->Top__DOT__exPayload1[2U] << 7U) | 
         (vlSelf->Top__DOT__exPayload1[1U] >> 0x19U));
    vlSelf->Top__DOT__execute__DOT__result1 = 0U;
    if ((0x80000U & vlSelf->Top__DOT__exPayload1[0U])) {
        if ((1U & (~ (vlSelf->Top__DOT__exPayload1[0U] 
                      >> 0x12U)))) {
            if ((1U & (~ (vlSelf->Top__DOT__exPayload1[0U] 
                          >> 0x11U)))) {
                vlSelf->Top__DOT__execute__DOT__result1 
                    = ((0x10000U & vlSelf->Top__DOT__exPayload1[0U])
                        ? ((vlSelf->Top__DOT__execute__DOT__upperOperand1 
                            < vlSelf->Top__DOT__execute__DOT__upperOperand2)
                            ? 1U : 0U) : (VL_LTS_III(32, vlSelf->Top__DOT__execute__DOT__upperOperand1, vlSelf->Top__DOT__execute__DOT__upperOperand2)
                                           ? 1U : 0U));
            }
        }
    } else {
        vlSelf->Top__DOT__execute__DOT__result1 = (
                                                   (0x40000U 
                                                    & vlSelf->Top__DOT__exPayload1[0U])
                                                    ? 
                                                   ((0x20000U 
                                                     & vlSelf->Top__DOT__exPayload1[0U])
                                                     ? 
                                                    ((0x10000U 
                                                      & vlSelf->Top__DOT__exPayload1[0U])
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlSelf->Top__DOT__execute__DOT__upperOperand1, 
                                                                    (0x1fU 
                                                                     & vlSelf->Top__DOT__execute__DOT__upperOperand2))
                                                      : 
                                                     (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelf->Top__DOT__execute__DOT__upperOperand2)))
                                                     : 
                                                    ((0x10000U 
                                                      & vlSelf->Top__DOT__exPayload1[0U])
                                                      ? 
                                                     (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                                      << 
                                                      (0x1fU 
                                                       & vlSelf->Top__DOT__execute__DOT__upperOperand2))
                                                      : 
                                                     (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                                      ^ vlSelf->Top__DOT__execute__DOT__upperOperand2)))
                                                    : 
                                                   ((0x20000U 
                                                     & vlSelf->Top__DOT__exPayload1[0U])
                                                     ? 
                                                    ((0x10000U 
                                                      & vlSelf->Top__DOT__exPayload1[0U])
                                                      ? 
                                                     (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                                      | vlSelf->Top__DOT__execute__DOT__upperOperand2)
                                                      : 
                                                     (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                                      & vlSelf->Top__DOT__execute__DOT__upperOperand2))
                                                     : 
                                                    ((0x10000U 
                                                      & vlSelf->Top__DOT__exPayload1[0U])
                                                      ? 
                                                     (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                                      - vlSelf->Top__DOT__execute__DOT__upperOperand2)
                                                      : 
                                                     (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                                      + vlSelf->Top__DOT__execute__DOT__upperOperand2))));
    }
    vlSelf->Top__DOT__nextFreeSlots = (0x1fU & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots) 
                                                + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__retireCount)));
    vlSelf->Top__DOT__decodeIssue__DOT__reasonIllegal2 = 0U;
    Top__DOT__destRegLoad2 = ((0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)) 
                              && (1U & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                         [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2] 
                                         >> 7U) & (~ 
                                                   (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                    [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2] 
                                                    >> 1U)))));
    vlSelf->Top__DOT__decodeIssue__DOT__reasonSlot1Memory = 0U;
    Top__DOT__lowerInFlightLoad1 = ((0U != (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                                            >> 0x1bU)) 
                                    && (1U & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                               [(vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                                                 >> 0x1bU)] 
                                               >> 7U) 
                                              & (~ 
                                                 (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                  [
                                                  (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                                                   >> 0x1bU)] 
                                                  >> 1U)))));
    Top__DOT__lowerInFlightLoad2 = ((0U != (0x1fU & 
                                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])) 
                                    && (1U & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                               [(0x1fU 
                                                 & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])] 
                                               >> 7U) 
                                              & (~ 
                                                 (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                  [
                                                  (0x1fU 
                                                   & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])] 
                                                  >> 1U)))));
    vlSelf->Top__DOT__decodeIssue__DOT__reasonIllegal1 = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__reasonWawConflict = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable = 0U;
    Top__DOT__destRegLoad1 = ((0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)) 
                              && (1U & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                         [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1] 
                                         >> 7U) & (~ 
                                                   (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                    [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1] 
                                                    >> 1U)))));
    vlSelf->Top__DOT__decodeIssue__DOT__reasonBackwardDependency = 0U;
    Top__DOT__upperInFlightLoad2 = ((0U != (0x1fU & 
                                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U])) 
                                    && (1U & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                               [(0x1fU 
                                                 & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U])] 
                                               >> 7U) 
                                              & (~ 
                                                 (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                  [
                                                  (0x1fU 
                                                   & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U])] 
                                                  >> 1U)))));
    Top__DOT__upperInFlightLoad1 = ((0U != (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                                            >> 0x1bU)) 
                                    && (1U & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                               [(vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                                                 >> 0x1bU)] 
                                               >> 7U) 
                                              & (~ 
                                                 (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                  [
                                                  (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                                                   >> 0x1bU)] 
                                                  >> 1U)))));
    vlSelf->Top__DOT__redirect1 = 0U;
    if ((1U & vlSelf->Top__DOT__exPayload1[0U])) {
        if ((0x2000U & vlSelf->Top__DOT__exPayload1[0U])) {
            if ((0x1000U & vlSelf->Top__DOT__exPayload1[0U])) {
                if ((1U & (~ (vlSelf->Top__DOT__exPayload1[0U] 
                              >> 0xbU)))) {
                    vlSelf->Top__DOT__redirect1 = (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                                   >= vlSelf->Top__DOT__execute__DOT__upperOperand2);
                }
            } else {
                vlSelf->Top__DOT__redirect1 = ((0x800U 
                                                & vlSelf->Top__DOT__exPayload1[0U])
                                                ? (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                                   < vlSelf->Top__DOT__execute__DOT__upperOperand2)
                                                : VL_GTES_III(32, vlSelf->Top__DOT__execute__DOT__upperOperand1, vlSelf->Top__DOT__execute__DOT__upperOperand2));
            }
        } else if ((0x1000U & vlSelf->Top__DOT__exPayload1[0U])) {
            vlSelf->Top__DOT__redirect1 = ((0x800U 
                                            & vlSelf->Top__DOT__exPayload1[0U])
                                            ? VL_LTS_III(32, vlSelf->Top__DOT__execute__DOT__upperOperand1, vlSelf->Top__DOT__execute__DOT__upperOperand2)
                                            : (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                               != vlSelf->Top__DOT__execute__DOT__upperOperand2));
        } else if ((0x800U & vlSelf->Top__DOT__exPayload1[0U])) {
            vlSelf->Top__DOT__redirect1 = (vlSelf->Top__DOT__execute__DOT__upperOperand1 
                                           == vlSelf->Top__DOT__execute__DOT__upperOperand2);
        }
        if ((0U != (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                          >> 0xeU)))) {
            if ((1U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                              >> 0xeU)))) {
                vlSelf->Top__DOT__redirect1 = 1U;
            } else if ((2U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                                     >> 0xeU)))) {
                vlSelf->Top__DOT__redirect1 = 1U;
            }
        }
    } else {
        vlSelf->Top__DOT__redirect1 = 0U;
    }
    Top__DOT__execute__DOT__illegal1 = 0U;
    Top__DOT__execute__DOT__redirectVector1 = ((vlSelf->Top__DOT__exPayload1[1U] 
                                                << 7U) 
                                               | (vlSelf->Top__DOT__exPayload1[0U] 
                                                  >> 0x19U));
    if (((IData)((0U != (0xf800U & vlSelf->Top__DOT__exPayload1[0U]))) 
         & vlSelf->Top__DOT__exPayload1[0U])) {
        if ((2U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                          >> 0xeU)))) {
            Top__DOT__execute__DOT__redirectVector1 
                = (0xfffffffeU & vlSelf->Top__DOT__execute__DOT__result1);
        } else if ((1U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                                 >> 0xeU)))) {
            Top__DOT__execute__DOT__redirectVector1 
                = vlSelf->Top__DOT__execute__DOT__result1;
        }
        if ((0U != (3U & Top__DOT__execute__DOT__redirectVector1))) {
            Top__DOT__execute__DOT__illegal1 = 1U;
        }
    }
    vlSelf->Top__DOT__execute__DOT__lowerOperand1 = 
        ((2U & vlSelf->Top__DOT__exPayload2[0U]) ? vlSelf->Top__DOT__execute__DOT__result1
          : ((vlSelf->Top__DOT__exPayload2[3U] << 0xaU) 
             | (vlSelf->Top__DOT__exPayload2[2U] >> 0x16U)));
    vlSelf->Top__DOT__execute__DOT__lowerOperand2 = 
        ((4U & vlSelf->Top__DOT__exPayload2[0U]) ? vlSelf->Top__DOT__execute__DOT__result1
          : ((vlSelf->Top__DOT__exPayload2[2U] << 0xaU) 
             | (vlSelf->Top__DOT__exPayload2[1U] >> 0x16U)));
    vlSelf->Top__DOT__decodeIssue__DOT__reasonRobFull = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__reasonRobOneFree = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__reasonLowerLoadHazard = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__reasonUpperLoadHazard = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__block1 = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__block2 = 0U;
    vlSelf->Top__DOT__resultPayload1 = 0ULL;
    vlSelf->Top__DOT__resultPayload1 = ((0x3fffffffffULL 
                                         & vlSelf->Top__DOT__resultPayload1) 
                                        | ((QData)((IData)(
                                                           (0x1fU 
                                                            & (vlSelf->Top__DOT__exPayload1[0U] 
                                                               >> 1U)))) 
                                           << 0x26U));
    if ((1U & ((vlSelf->Top__DOT__exPayload1[0U] & 
                (~ (IData)(vlSelf->Top__DOT__redirect1))) 
               & (~ (IData)(vlSelf->reset))))) {
        vlSelf->Top__DOT__resultPayload1 = ((0x7ffffffffc0ULL 
                                             & vlSelf->Top__DOT__resultPayload1) 
                                            | (IData)((IData)(
                                                              (1U 
                                                               | (0x3eU 
                                                                  & (vlSelf->Top__DOT__exPayload1[0U] 
                                                                     >> 0x13U))))));
        vlSelf->Top__DOT__resultPayload1 = ((0x7c00000003fULL 
                                             & vlSelf->Top__DOT__resultPayload1) 
                                            | ((QData)((IData)(
                                                               ((0U 
                                                                 != 
                                                                 (3U 
                                                                  & (vlSelf->Top__DOT__exPayload1[0U] 
                                                                     >> 0xeU)))
                                                                 ? 
                                                                ((vlSelf->Top__DOT__exPayload1[1U] 
                                                                  << 7U) 
                                                                 | (vlSelf->Top__DOT__exPayload1[0U] 
                                                                    >> 0x19U))
                                                                 : vlSelf->Top__DOT__execute__DOT__result1))) 
                                               << 6U));
    }
    Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0 
        = ((~ (IData)(Top__DOT__execute__DOT__illegal1)) 
           & (IData)(vlSelf->Top__DOT__redirect1));
    Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0 
        = VL_LTS_III(32, vlSelf->Top__DOT__execute__DOT__lowerOperand1, vlSelf->Top__DOT__execute__DOT__lowerOperand2);
    Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0 
        = (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
           < vlSelf->Top__DOT__execute__DOT__lowerOperand2);
    vlSelf->Top__DOT__redirect2 = 0U;
    if ((1U & vlSelf->Top__DOT__exPayload2[0U])) {
        if ((0x400U & vlSelf->Top__DOT__exPayload2[0U])) {
            if ((0x200U & vlSelf->Top__DOT__exPayload2[0U])) {
                if ((1U & (~ (vlSelf->Top__DOT__exPayload2[0U] 
                              >> 8U)))) {
                    vlSelf->Top__DOT__redirect2 = (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                                   >= vlSelf->Top__DOT__execute__DOT__lowerOperand2);
                }
            } else {
                vlSelf->Top__DOT__redirect2 = ((0x100U 
                                                & vlSelf->Top__DOT__exPayload2[0U])
                                                ? (IData)(Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0)
                                                : VL_GTES_III(32, vlSelf->Top__DOT__execute__DOT__lowerOperand1, vlSelf->Top__DOT__execute__DOT__lowerOperand2));
            }
        } else if ((0x200U & vlSelf->Top__DOT__exPayload2[0U])) {
            vlSelf->Top__DOT__redirect2 = ((0x100U 
                                            & vlSelf->Top__DOT__exPayload2[0U])
                                            ? (IData)(Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0)
                                            : (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                               != vlSelf->Top__DOT__execute__DOT__lowerOperand2));
        } else if ((0x100U & vlSelf->Top__DOT__exPayload2[0U])) {
            vlSelf->Top__DOT__redirect2 = (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                           == vlSelf->Top__DOT__execute__DOT__lowerOperand2);
        }
        if ((0U != (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                          >> 0xbU)))) {
            if ((1U == (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                              >> 0xbU)))) {
                vlSelf->Top__DOT__redirect2 = 1U;
            } else if ((2U == (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                                     >> 0xbU)))) {
                vlSelf->Top__DOT__redirect2 = 1U;
            }
        }
    } else {
        vlSelf->Top__DOT__redirect2 = 0U;
    }
    vlSelf->Top__DOT__execute__DOT__result2 = 0U;
    if ((0x10000U & vlSelf->Top__DOT__exPayload2[0U])) {
        if ((1U & (~ (vlSelf->Top__DOT__exPayload2[0U] 
                      >> 0xfU)))) {
            if ((1U & (~ (vlSelf->Top__DOT__exPayload2[0U] 
                          >> 0xeU)))) {
                vlSelf->Top__DOT__execute__DOT__result2 
                    = ((0x2000U & vlSelf->Top__DOT__exPayload2[0U])
                        ? ((IData)(Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0)
                            ? 1U : 0U) : ((IData)(Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0)
                                           ? 1U : 0U));
            }
        }
    } else {
        vlSelf->Top__DOT__execute__DOT__result2 = (
                                                   (0x8000U 
                                                    & vlSelf->Top__DOT__exPayload2[0U])
                                                    ? 
                                                   ((0x4000U 
                                                     & vlSelf->Top__DOT__exPayload2[0U])
                                                     ? 
                                                    ((0x2000U 
                                                      & vlSelf->Top__DOT__exPayload2[0U])
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlSelf->Top__DOT__execute__DOT__lowerOperand1, 
                                                                    (0x1fU 
                                                                     & vlSelf->Top__DOT__execute__DOT__lowerOperand2))
                                                      : 
                                                     (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelf->Top__DOT__execute__DOT__lowerOperand2)))
                                                     : 
                                                    ((0x2000U 
                                                      & vlSelf->Top__DOT__exPayload2[0U])
                                                      ? 
                                                     (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                                      << 
                                                      (0x1fU 
                                                       & vlSelf->Top__DOT__execute__DOT__lowerOperand2))
                                                      : 
                                                     (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                                      ^ vlSelf->Top__DOT__execute__DOT__lowerOperand2)))
                                                    : 
                                                   ((0x4000U 
                                                     & vlSelf->Top__DOT__exPayload2[0U])
                                                     ? 
                                                    ((0x2000U 
                                                      & vlSelf->Top__DOT__exPayload2[0U])
                                                      ? 
                                                     (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                                      | vlSelf->Top__DOT__execute__DOT__lowerOperand2)
                                                      : 
                                                     (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                                      & vlSelf->Top__DOT__execute__DOT__lowerOperand2))
                                                     : 
                                                    ((0x2000U 
                                                      & vlSelf->Top__DOT__exPayload2[0U])
                                                      ? 
                                                     (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                                      - vlSelf->Top__DOT__execute__DOT__lowerOperand2)
                                                      : 
                                                     (vlSelf->Top__DOT__execute__DOT__lowerOperand1 
                                                      + vlSelf->Top__DOT__execute__DOT__lowerOperand2))));
    }
    Top__DOT__execute__DOT__illegal2 = 0U;
    Top__DOT__execute__DOT__redirectVector2 = ((vlSelf->Top__DOT__exPayload2[1U] 
                                                << 0xaU) 
                                               | (vlSelf->Top__DOT__exPayload2[0U] 
                                                  >> 0x16U));
    if (((IData)((0U != (0x1f00U & vlSelf->Top__DOT__exPayload2[0U]))) 
         & vlSelf->Top__DOT__exPayload2[0U])) {
        if ((2U == (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                          >> 0xbU)))) {
            Top__DOT__execute__DOT__redirectVector2 
                = (0xfffffffeU & vlSelf->Top__DOT__execute__DOT__result2);
        } else if ((1U == (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                                 >> 0xbU)))) {
            Top__DOT__execute__DOT__redirectVector2 
                = vlSelf->Top__DOT__execute__DOT__result2;
        }
        if ((0U != (3U & Top__DOT__execute__DOT__redirectVector2))) {
            Top__DOT__execute__DOT__illegal2 = 1U;
        }
    }
    Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0 
        = ((~ (IData)(Top__DOT__execute__DOT__illegal2)) 
           & (IData)(vlSelf->Top__DOT__redirect2));
    vlSelf->Top__DOT__redirectVector = ((IData)(Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0)
                                         ? Top__DOT__execute__DOT__redirectVector1
                                         : ((IData)(Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0)
                                             ? Top__DOT__execute__DOT__redirectVector2
                                             : 0U));
    vlSelf->Top__DOT__redirect = ((IData)(Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0) 
                                  | (IData)(Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0));
    if (vlSelf->reset) {
        vlSelf->Top__DOT__instructionMemory__DOT__redirectAddress = 0U;
        vlSelf->Top__DOT__instructionMemory__DOT__nextAddress = 0x10U;
    } else {
        vlSelf->Top__DOT__instructionMemory__DOT__redirectAddress 
            = vlSelf->Top__DOT__redirectVector;
        vlSelf->Top__DOT__instructionMemory__DOT__nextAddress 
            = ((IData)(0x10U) + vlSelf->Top__DOT__redirectVector);
    }
    vlSelf->Top__DOT__instructionConsumed1 = 0U;
    vlSelf->Top__DOT__instructionConsumed2 = 0U;
    if (vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid) {
        if (Top__DOT__decodeIssue__DOT__illegal2) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonIllegal2 = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (Top__DOT__decodeIssue__DOT__illegal1) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonIllegal1 = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((0U != (3U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                          >> 0x12U)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonSlot1Memory = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
             == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonWawConflict = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__decodeIssue__DOT__internalBadData) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonBadFetch = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((((vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
               >> 0x1bU) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)) 
             & (0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable 
                = (1U | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable));
        }
        if ((((0x1fU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
              == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)) 
             & (0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable 
                = (2U | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable));
        }
        if ((1U != (IData)(vlSelf->Top__DOT__nextFreeSlots))) {
            if ((0U == (IData)(vlSelf->Top__DOT__nextFreeSlots))) {
                vlSelf->Top__DOT__decodeIssue__DOT__reasonRobFull = 1U;
                vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
            }
        }
        if ((1U == (IData)(vlSelf->Top__DOT__nextFreeSlots))) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonRobOneFree = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        } else if ((0U == (IData)(vlSelf->Top__DOT__nextFreeSlots))) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((((IData)(Top__DOT__upperInFlightLoad1) 
              | (IData)(Top__DOT__upperInFlightLoad2)) 
             | (IData)(Top__DOT__destRegLoad1))) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonUpperLoadHazard = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((((IData)(Top__DOT__lowerInFlightLoad1) 
              | (IData)(Top__DOT__lowerInFlightLoad2)) 
             | (IData)(Top__DOT__destRegLoad2))) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonLowerLoadHazard = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (((((vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                >> 0x1bU) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)) 
              & (0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) 
             | (((0x1fU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                 == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)) 
                & (0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))))) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonBackwardDependency = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
    } else {
        vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
        vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
    }
    if ((1U & ((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->Top__DOT__redirect))))) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__decodeIssue__DOT__block1)) 
                   & (~ (IData)(vlSelf->Top__DOT__decodeIssue__DOT__block2))))) {
            vlSelf->Top__DOT__instructionConsumed1 = 1U;
            vlSelf->Top__DOT__instructionConsumed2 = 1U;
        } else if ((1U & (~ (IData)(vlSelf->Top__DOT__decodeIssue__DOT__block1)))) {
            vlSelf->Top__DOT__instructionConsumed1 = 1U;
        }
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
    vlSelf->Top__DOT__resultPayload2 = 0ULL;
    vlSelf->Top__DOT__resultPayload2 = ((0x3fffffffffULL 
                                         & vlSelf->Top__DOT__resultPayload2) 
                                        | ((QData)((IData)(
                                                           (0x1fU 
                                                            & (vlSelf->Top__DOT__exPayload2[0U] 
                                                               >> 3U)))) 
                                           << 0x26U));
    if ((1U & ((vlSelf->Top__DOT__exPayload2[0U] & 
                (~ (IData)(vlSelf->Top__DOT__redirect))) 
               & (~ (IData)(vlSelf->reset))))) {
        vlSelf->Top__DOT__resultPayload2 = ((0x7ffffffffc0ULL 
                                             & vlSelf->Top__DOT__resultPayload2) 
                                            | (IData)((IData)(
                                                              (1U 
                                                               | (0x3eU 
                                                                  & (vlSelf->Top__DOT__exPayload2[0U] 
                                                                     >> 0x10U))))));
        vlSelf->Top__DOT__resultPayload2 = ((0x7c00000003fULL 
                                             & vlSelf->Top__DOT__resultPayload2) 
                                            | ((QData)((IData)(
                                                               ((0U 
                                                                 != 
                                                                 (3U 
                                                                  & (vlSelf->Top__DOT__exPayload2[0U] 
                                                                     >> 0xbU)))
                                                                 ? 
                                                                ((vlSelf->Top__DOT__exPayload2[1U] 
                                                                  << 0xaU) 
                                                                 | (vlSelf->Top__DOT__exPayload2[0U] 
                                                                    >> 0x16U))
                                                                 : vlSelf->Top__DOT__execute__DOT__result2))) 
                                               << 6U));
    }
    vlSelf->Top__DOT__instructionPacket1 = 0ULL;
    vlSelf->Top__DOT__instructionPacket2 = 0ULL;
    if (((IData)(vlSelf->Top__DOT__instructionConsumed1) 
         & (IData)(vlSelf->Top__DOT__instructionConsumed2))) {
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U];
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[1U] 
            = vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U];
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[2U] 
            = vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U];
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[3U] 
            = vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[3U];
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
            = ((0x7ffffU & vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]) 
               | ((IData)(((0x7fffffffffe0ULL & (((QData)((IData)(
                                                                  vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])) 
                                                  << 0x2aU) 
                                                 | (((QData)((IData)(
                                                                     vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U])) 
                                                     << 0xaU) 
                                                    | (0x3ffffffffe0ULL 
                                                       & ((QData)((IData)(
                                                                          vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U])) 
                                                          >> 0x16U))))) 
                           | (QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)))) 
                  << 0x13U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[1U] 
            = (((IData)(((0x7fffffffffe0ULL & (((QData)((IData)(
                                                                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])) 
                                                << 0x2aU) 
                                               | (((QData)((IData)(
                                                                   vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U])) 
                                                   << 0xaU) 
                                                  | (0x3ffffffffe0ULL 
                                                     & ((QData)((IData)(
                                                                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U])) 
                                                        >> 0x16U))))) 
                         | (QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)))) 
                >> 0xdU) | ((IData)((((0x7fffffffffe0ULL 
                                       & (((QData)((IData)(
                                                           vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])) 
                                           << 0x2aU) 
                                          | (((QData)((IData)(
                                                              vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U])) 
                                              << 0xaU) 
                                             | (0x3ffffffffe0ULL 
                                                & ((QData)((IData)(
                                                                   vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U])) 
                                                   >> 0x16U))))) 
                                      | (QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) 
                                     >> 0x20U)) << 0x13U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[2U] 
            = (((0x7fffcU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                             >> 3U)) | ((IData)((((0x7fffffffffe0ULL 
                                                   & (((QData)((IData)(
                                                                       vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])) 
                                                       << 0x2aU) 
                                                      | (((QData)((IData)(
                                                                          vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U])) 
                                                          << 0xaU) 
                                                         | (0x3ffffffffe0ULL 
                                                            & ((QData)((IData)(
                                                                               vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U])) 
                                                               >> 0x16U))))) 
                                                  | (QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) 
                                                 >> 0x20U)) 
                                        >> 0xdU)) | 
               (0xfff80000U & ((vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[3U] 
                                << 0x1dU) | (0x1ff80000U 
                                             & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                >> 3U)))));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[3U] 
            = (3U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[3U] 
                     >> 3U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = ((0xf83fffffU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
               | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                  << 0x16U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
            = ((0xfff803ffU & vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]) 
               | (0xfffffc00U & ((0x60000U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                              >> 3U)) 
                                 | (0x1fc00U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                                << 2U)))));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = (1U | ((0xffffffc0U & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
                     | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__issue1AgeTag) 
                        << 1U)));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
            = (1U | ((0xfffffc00U & vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]) 
                     | ((0x300U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                   << 2U)) | (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__issue2AgeTag) 
                                               << 3U) 
                                              | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable) 
                                                 << 1U)))));
        vlSelf->Top__DOT__instructionPacket1 = ((1ULL 
                                                 & vlSelf->Top__DOT__instructionPacket1) 
                                                | (((QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__PC1)) 
                                                    << 0xcU) 
                                                   | ((QData)((IData)(
                                                                      (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                                                                        << 6U) 
                                                                       | (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__issue1AgeTag) 
                                                                           << 1U) 
                                                                          | (2U 
                                                                             == 
                                                                             (3U 
                                                                              & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                                                                >> 0x12U))))))) 
                                                      << 1U)));
        vlSelf->Top__DOT__instructionPacket1 = (1ULL 
                                                | vlSelf->Top__DOT__instructionPacket1);
        vlSelf->Top__DOT__instructionPacket2 = ((1ULL 
                                                 & vlSelf->Top__DOT__instructionPacket2) 
                                                | (((QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__PC2)) 
                                                    << 0xcU) 
                                                   | ((QData)((IData)(
                                                                      (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2) 
                                                                        << 6U) 
                                                                       | (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__issue2AgeTag) 
                                                                           << 1U) 
                                                                          | (2U 
                                                                             == 
                                                                             (3U 
                                                                              & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                                                                >> 0x12U))))))) 
                                                      << 1U)));
        vlSelf->Top__DOT__instructionPacket2 = (1ULL 
                                                | vlSelf->Top__DOT__instructionPacket2);
    } else if (vlSelf->Top__DOT__instructionConsumed1) {
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U];
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[1U] 
            = vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U];
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[2U] 
            = vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U];
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[3U] 
            = vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[3U];
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[1U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[2U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[3U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = ((0xf83fffffU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
               | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                  << 0x16U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = (1U | ((0xffffffc0U & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
                     | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__issue1AgeTag) 
                        << 1U)));
        vlSelf->Top__DOT__instructionPacket1 = ((1ULL 
                                                 & vlSelf->Top__DOT__instructionPacket1) 
                                                | (((QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__PC1)) 
                                                    << 0xcU) 
                                                   | ((QData)((IData)(
                                                                      (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                                                                        << 6U) 
                                                                       | (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__issue1AgeTag) 
                                                                           << 1U) 
                                                                          | (2U 
                                                                             == 
                                                                             (3U 
                                                                              & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                                                                >> 0x12U))))))) 
                                                      << 1U)));
        vlSelf->Top__DOT__instructionPacket1 = (1ULL 
                                                | vlSelf->Top__DOT__instructionPacket1);
    } else {
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[1U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[2U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[3U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[1U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[2U] = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[3U] = 0U;
    }
    Top__DOT__reorderBuffer__DOT__ageVector = (0x1fU 
                                               & ((IData)(vlSelf->Top__DOT__upperSource1Status) 
                                                  >> 1U));
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 1U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [1U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[1U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 2U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [2U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[2U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 3U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [3U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[3U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 4U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [4U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[4U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 5U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [5U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[5U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 6U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [6U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[6U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 7U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [7U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[7U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 8U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [8U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[8U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 9U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [9U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[9U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xaU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xaU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xaU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xbU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xbU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xbU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xcU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xcU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xcU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xdU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xdU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xdU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xeU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xeU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xeU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xfU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xfU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xfU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT__ageVector = (0x1fU 
                                               & ((IData)(vlSelf->Top__DOT__upperSource2Status) 
                                                  >> 1U));
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 1U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [1U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[1U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 2U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [2U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[2U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 3U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [3U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[3U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 4U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [4U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[4U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 5U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [5U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[5U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 6U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [6U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[6U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 7U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [7U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[7U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 8U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [8U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[8U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 9U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [9U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[9U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xaU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xaU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xaU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xbU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xbU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xbU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xcU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xcU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xcU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xdU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xdU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xdU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xeU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xeU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xeU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xfU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xfU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xfU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT__ageVector = (0x1fU 
                                               & ((IData)(vlSelf->Top__DOT__lowerSource1Status) 
                                                  >> 1U));
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 1U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [1U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[1U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 2U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [2U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[2U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 3U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [3U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[3U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 4U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [4U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[4U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 5U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [5U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[5U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 6U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [6U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[6U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 7U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [7U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[7U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 8U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [8U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[8U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 9U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [9U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[9U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xaU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xaU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xaU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xbU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xbU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xbU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xcU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xcU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xcU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xdU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xdU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xdU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xeU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xeU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xeU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xfU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xfU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xfU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT__ageVector = (0x1fU 
                                               & ((IData)(vlSelf->Top__DOT__lowerSource2Status) 
                                                  >> 1U));
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 1U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [1U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[1U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 2U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [2U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[2U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 3U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [3U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[3U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 4U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [4U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[4U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 5U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [5U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[5U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 6U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [6U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[6U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 7U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [7U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[7U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 8U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [8U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[8U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 9U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [9U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[9U][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xaU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xaU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xaU][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xbU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xbU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xbU][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xcU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xcU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xcU][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xdU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xdU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xdU][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xeU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xeU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xeU][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xfU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xfU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xfU][3U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT__ageVector = (0x1fU 
                                               & (IData)(
                                                         (vlSelf->Top__DOT__resultPayload1 
                                                          >> 0x26U)));
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 1U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [1U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[1U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 2U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [2U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[2U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 3U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [3U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[3U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 4U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [4U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[4U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 5U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [5U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[5U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 6U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [6U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[6U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 7U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [7U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[7U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 8U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [8U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[8U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 9U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [9U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[9U][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xaU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xaU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xaU][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xbU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xbU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xbU][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xcU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xcU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xcU][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xdU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xdU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xdU][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xeU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xeU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xeU][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xfU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xfU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xfU][4U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT__ageVector = (0x1fU 
                                               & (IData)(
                                                         (vlSelf->Top__DOT__resultPayload2 
                                                          >> 0x26U)));
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 1U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [1U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[1U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 2U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [2U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[2U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 3U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [3U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[3U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 4U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [4U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[4U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 5U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [5U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[5U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 6U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [6U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[6U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 7U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [7U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[7U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 8U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [8U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[8U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 9U, (0x1fU & ((IData)(0x10U) 
                                        - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [9U][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[9U][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xaU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xaU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xaU][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xbU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xbU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xbU][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xcU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xcU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xcU][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xdU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xdU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xdU][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xeU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xeU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xeU][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0 
        = (VL_LTS_III(32, 0xfU, (0x1fU & ((IData)(0x10U) 
                                          - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xfU][0U] >> 2U)) == (IData)(Top__DOT__reorderBuffer__DOT__ageVector)));
    vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[0xfU][5U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hcd25f868__0;
    vlSelf->Top__DOT__instruction1 = 0xdeadbeefU;
    if (((vlSelf->Top__DOT__requestPC1 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow 
                                                  >> 4U))) {
        vlSelf->Top__DOT__instruction1 = ((8U & vlSelf->Top__DOT__requestPC1)
                                           ? ((4U & vlSelf->Top__DOT__requestPC1)
                                               ? vlSelf->Top__DOT__lowFetchData[3U]
                                               : vlSelf->Top__DOT__lowFetchData[2U])
                                           : ((4U & vlSelf->Top__DOT__requestPC1)
                                               ? vlSelf->Top__DOT__lowFetchData[1U]
                                               : vlSelf->Top__DOT__lowFetchData[0U]));
    }
    if (((vlSelf->Top__DOT__requestPC1 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow 
                                                  >> 4U))) {
        vlSelf->Top__DOT__instruction1 = ((8U & vlSelf->Top__DOT__requestPC1)
                                           ? ((4U & vlSelf->Top__DOT__requestPC1)
                                               ? vlSelf->Top__DOT__highFetchData[3U]
                                               : vlSelf->Top__DOT__highFetchData[2U])
                                           : ((4U & vlSelf->Top__DOT__requestPC1)
                                               ? vlSelf->Top__DOT__highFetchData[1U]
                                               : vlSelf->Top__DOT__highFetchData[0U]));
    }
    vlSelf->Top__DOT__instruction2 = 0xdeadbeefU;
    if (((vlSelf->Top__DOT__requestPC2 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow 
                                                  >> 4U))) {
        vlSelf->Top__DOT__instruction2 = ((8U & vlSelf->Top__DOT__requestPC2)
                                           ? ((4U & vlSelf->Top__DOT__requestPC2)
                                               ? vlSelf->Top__DOT__lowFetchData[3U]
                                               : vlSelf->Top__DOT__lowFetchData[2U])
                                           : ((4U & vlSelf->Top__DOT__requestPC2)
                                               ? vlSelf->Top__DOT__lowFetchData[1U]
                                               : vlSelf->Top__DOT__lowFetchData[0U]));
    }
    if (((vlSelf->Top__DOT__requestPC2 >> 4U) == (vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow 
                                                  >> 4U))) {
        vlSelf->Top__DOT__instruction2 = ((8U & vlSelf->Top__DOT__requestPC2)
                                           ? ((4U & vlSelf->Top__DOT__requestPC2)
                                               ? vlSelf->Top__DOT__highFetchData[3U]
                                               : vlSelf->Top__DOT__highFetchData[2U])
                                           : ((4U & vlSelf->Top__DOT__requestPC2)
                                               ? vlSelf->Top__DOT__highFetchData[1U]
                                               : vlSelf->Top__DOT__highFetchData[0U]));
    }
    Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0U;
    if (vlSelf->Top__DOT__redirect) {
        if (vlSelf->Top__DOT__redirect1) {
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [1U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 1U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [2U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 2U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [3U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 3U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [4U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 4U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [5U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 5U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [6U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 6U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [7U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 7U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [8U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 8U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [9U][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 9U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xaU][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xaU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xbU][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xbU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xcU][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xcU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xdU][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xdU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xeU][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xeU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xfU][4U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xfU;
            }
        } else if (vlSelf->Top__DOT__redirect2) {
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [1U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 1U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [2U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 2U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [3U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 3U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [4U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 4U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [5U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 5U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [6U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 6U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [7U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 7U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [8U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 8U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [9U][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 9U;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xaU][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xaU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xbU][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xbU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xcU][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xcU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xdU][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xdU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xeU][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xeU;
            }
            if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
                [0xfU][5U]) {
                Top__DOT__reorderBuffer__DOT__redirectNextTailPointer = 0xfU;
            }
        }
    }
    Top__DOT__lowerROBData2 = 0U;
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [1U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [1U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [1U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [2U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [2U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [2U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [3U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [3U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [3U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [4U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [4U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [4U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [5U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [5U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [5U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [6U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [6U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [6U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [7U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [7U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [7U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [8U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [8U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [8U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [9U][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [9U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [9U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xaU][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xaU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xaU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xbU][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xbU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xbU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xcU][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xcU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xcU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xdU][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xdU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xdU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xeU][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xeU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xeU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xfU][3U]) {
        Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xfU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xfU][0U] >> 0xcU));
    }
    Top__DOT__lowerROBData1 = 0U;
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [1U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [1U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [1U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [2U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [2U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [2U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [3U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [3U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [3U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [4U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [4U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [4U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [5U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [5U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [5U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [6U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [6U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [6U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [7U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [7U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [7U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [8U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [8U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [8U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [9U][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [9U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [9U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xaU][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xaU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xaU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xbU][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xbU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xbU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xcU][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xcU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xcU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xdU][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xdU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xdU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xeU][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xeU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xeU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xfU][2U]) {
        Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xfU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xfU][0U] >> 0xcU));
    }
    Top__DOT__upperROBData2 = 0U;
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [1U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [1U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [1U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [2U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [2U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [2U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [3U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [3U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [3U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [4U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [4U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [4U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [5U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [5U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [5U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [6U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [6U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [6U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [7U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [7U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [7U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [8U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [8U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [8U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [9U][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [9U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [9U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xaU][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xaU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xaU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xbU][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xbU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xbU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xcU][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xcU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xcU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xdU][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xdU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xdU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xeU][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xeU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xeU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xfU][1U]) {
        Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xfU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xfU][0U] >> 0xcU));
    }
    Top__DOT__upperROBData1 = 0U;
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [1U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [1U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [1U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [2U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [2U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [2U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [3U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [3U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [3U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [4U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [4U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [4U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [5U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [5U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [5U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [6U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [6U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [6U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [7U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [7U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [7U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [8U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [8U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [8U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [9U][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [9U][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [9U][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xaU][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xaU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xaU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xbU][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xbU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xbU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xcU][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xcU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xcU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xdU][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xdU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xdU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xeU][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xeU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xeU][0U] >> 0xcU));
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid
        [0xfU][0U]) {
        Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [0xfU][1U] << 0x14U) 
                                   | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [0xfU][0U] >> 0xcU));
    }
    vlSelf->Top__DOT__reorderBuffer__DOT__calculatedNextFreeSlots 
        = (0x1fU & (((((IData)(vlSelf->Top__DOT__redirect)
                        ? ((IData)(0xfU) - (IData)(Top__DOT__reorderBuffer__DOT__redirectNextTailPointer))
                        : (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots)) 
                      + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__retireCount)) 
                     - (1U & (IData)(vlSelf->Top__DOT__instructionPacket1))) 
                    - (1U & (IData)(vlSelf->Top__DOT__instructionPacket2))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[2U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[3U] = 0U;
    Top__DOT__operandSelect__DOT__lowerOperand1 = 0U;
    Top__DOT__operandSelect__DOT__lowerOperand2 = 0U;
    if ((0U == (0x1fU & (vlSelf->Top__DOT__payload2[1U] 
                         >> 0x18U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__lowerSource1Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = ((0U != (0x1fU & (vlSelf->Top__DOT__payload2[1U] 
                                >> 0x18U))) ? vlSelf->Top__DOT__registerFile__DOT__registerFile
               [(0x1fU & (vlSelf->Top__DOT__payload2[1U] 
                          >> 0x18U))] : 0U);
    } else if ((0x40U & (IData)(vlSelf->Top__DOT__lowerSource1Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = Top__DOT__lowerROBData1;
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__lowerSource1Status) 
                                                     >> 1U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__lowerSource1Status) 
                                                     >> 1U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    if ((0U == (0x1fU & ((vlSelf->Top__DOT__payload2[2U] 
                          << 3U) | (vlSelf->Top__DOT__payload2[1U] 
                                    >> 0x1dU))))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__lowerSource2Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = ((0U != (0x1fU & ((vlSelf->Top__DOT__payload2[2U] 
                                 << 3U) | (vlSelf->Top__DOT__payload2[1U] 
                                           >> 0x1dU))))
                ? vlSelf->Top__DOT__registerFile__DOT__registerFile
               [(0x1fU & ((vlSelf->Top__DOT__payload2[2U] 
                           << 3U) | (vlSelf->Top__DOT__payload2[1U] 
                                     >> 0x1dU)))] : 0U);
    } else if ((0x40U & (IData)(vlSelf->Top__DOT__lowerSource2Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = Top__DOT__lowerROBData2;
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__lowerSource2Status) 
                                                     >> 1U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__lowerSource2Status) 
                                                     >> 1U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] 
        = ((0x3fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U]) 
           | ((IData)(((0x40000U & vlSelf->Top__DOT__payload2[0U])
                        ? ((0x20000U & vlSelf->Top__DOT__payload2[0U])
                            ? (QData)((IData)(((vlSelf->Top__DOT__payload2[1U] 
                                                << 8U) 
                                               | (vlSelf->Top__DOT__payload2[0U] 
                                                  >> 0x18U))))
                            : (((QData)((IData)(((vlSelf->Top__DOT__payload2[3U] 
                                                  << 0x1eU) 
                                                 | (vlSelf->Top__DOT__payload2[2U] 
                                                    >> 2U)))) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[1U] 
                                                              << 8U) 
                                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                                >> 0x18U))))))
                        : ((0x20000U & vlSelf->Top__DOT__payload2[0U])
                            ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[1U] 
                                                              << 8U) 
                                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                                >> 0x18U)))))
                            : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2)))))) 
              << 0x16U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[2U] 
        = (((IData)(((0x40000U & vlSelf->Top__DOT__payload2[0U])
                      ? ((0x20000U & vlSelf->Top__DOT__payload2[0U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload2[1U] 
                                              << 8U) 
                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                >> 0x18U))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload2[3U] 
                                                << 0x1eU) 
                                               | (vlSelf->Top__DOT__payload2[2U] 
                                                  >> 2U)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[1U] 
                                                            << 8U) 
                                                           | (vlSelf->Top__DOT__payload2[0U] 
                                                              >> 0x18U))))))
                      : ((0x20000U & vlSelf->Top__DOT__payload2[0U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[1U] 
                                                            << 8U) 
                                                           | (vlSelf->Top__DOT__payload2[0U] 
                                                              >> 0x18U)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2)))))) 
            >> 0xaU) | ((IData)((((0x40000U & vlSelf->Top__DOT__payload2[0U])
                                   ? ((0x20000U & vlSelf->Top__DOT__payload2[0U])
                                       ? (QData)((IData)(
                                                         ((vlSelf->Top__DOT__payload2[1U] 
                                                           << 8U) 
                                                          | (vlSelf->Top__DOT__payload2[0U] 
                                                             >> 0x18U))))
                                       : (((QData)((IData)(
                                                           ((vlSelf->Top__DOT__payload2[3U] 
                                                             << 0x1eU) 
                                                            | (vlSelf->Top__DOT__payload2[2U] 
                                                               >> 2U)))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[1U] 
                                                              << 8U) 
                                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                                >> 0x18U))))))
                                   : ((0x20000U & vlSelf->Top__DOT__payload2[0U])
                                       ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[1U] 
                                                              << 8U) 
                                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                                >> 0x18U)))))
                                       : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                           << 0x20U) 
                                          | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2))))) 
                                 >> 0x20U)) << 0x16U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[3U] 
        = ((IData)((((0x40000U & vlSelf->Top__DOT__payload2[0U])
                      ? ((0x20000U & vlSelf->Top__DOT__payload2[0U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload2[1U] 
                                              << 8U) 
                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                >> 0x18U))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload2[3U] 
                                                << 0x1eU) 
                                               | (vlSelf->Top__DOT__payload2[2U] 
                                                  >> 2U)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[1U] 
                                                            << 8U) 
                                                           | (vlSelf->Top__DOT__payload2[0U] 
                                                              >> 0x18U))))))
                      : ((0x20000U & vlSelf->Top__DOT__payload2[0U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[1U] 
                                                            << 8U) 
                                                           | (vlSelf->Top__DOT__payload2[0U] 
                                                              >> 0x18U)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2))))) 
                    >> 0x20U)) >> 0xaU);
    if ((0U != (3U & (vlSelf->Top__DOT__payload2[0U] 
                      >> 8U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
            = ((0x3fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload2[3U] 
                                   << 0x1eU) | (vlSelf->Top__DOT__payload2[2U] 
                                                >> 2U))) 
                  << 0x16U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] 
            = ((0xffc00000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload2[3U] 
                                   << 0x1eU) | (vlSelf->Top__DOT__payload2[2U] 
                                                >> 2U))) 
                  >> 0xaU));
    } else if ((0U != (7U & (vlSelf->Top__DOT__payload2[0U] 
                             >> 0xeU)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
            = ((0x3fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
               | ((((vlSelf->Top__DOT__payload2[3U] 
                     << 0x1eU) | (vlSelf->Top__DOT__payload2[2U] 
                                  >> 2U)) + ((vlSelf->Top__DOT__payload2[1U] 
                                              << 8U) 
                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                >> 0x18U))) 
                  << 0x16U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] 
            = ((0xffc00000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U]) 
               | ((((vlSelf->Top__DOT__payload2[3U] 
                     << 0x1eU) | (vlSelf->Top__DOT__payload2[2U] 
                                  >> 2U)) + ((vlSelf->Top__DOT__payload2[1U] 
                                              << 8U) 
                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                >> 0x18U))) 
                  >> 0xaU));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xffc000ffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (0xffffff00U & ((0x3e0000U & (vlSelf->Top__DOT__payload2[0U] 
                                           >> 2U)) 
                             | ((0x1f800U & (vlSelf->Top__DOT__payload2[0U] 
                                             << 3U)) 
                                | (0x700U & (vlSelf->Top__DOT__payload2[0U] 
                                             >> 6U))))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xffffff07U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (0xf8U & vlSelf->Top__DOT__payload2[0U]));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xfffffffeU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | ((1U & ((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->Top__DOT__redirect)))) 
              && (1U & vlSelf->Top__DOT__payload2[0U])));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xfffffff9U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (6U & vlSelf->Top__DOT__payload2[0U]));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[2U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[3U] = 0U;
    Top__DOT__operandSelect__DOT__upperOperand1 = 0U;
    Top__DOT__operandSelect__DOT__upperOperand2 = 0U;
    if ((0U == (vlSelf->Top__DOT__payload1[1U] >> 0x1bU))) {
        Top__DOT__operandSelect__DOT__upperOperand1 = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__upperSource1Status))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = ((0U != (vlSelf->Top__DOT__payload1[1U] 
                       >> 0x1bU)) ? vlSelf->Top__DOT__registerFile__DOT__registerFile
               [(vlSelf->Top__DOT__payload1[1U] >> 0x1bU)]
                : 0U);
    } else if ((0x40U & (IData)(vlSelf->Top__DOT__upperSource1Status))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = Top__DOT__upperROBData1;
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__upperSource1Status) 
                                                     >> 1U)))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__upperSource1Status) 
                                                     >> 1U)))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    if ((0U == (0x1fU & vlSelf->Top__DOT__payload1[2U]))) {
        Top__DOT__operandSelect__DOT__upperOperand2 = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__upperSource2Status))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = ((0U != (0x1fU & vlSelf->Top__DOT__payload1[2U]))
                ? vlSelf->Top__DOT__registerFile__DOT__registerFile
               [(0x1fU & vlSelf->Top__DOT__payload1[2U])]
                : 0U);
    } else if ((0x40U & (IData)(vlSelf->Top__DOT__upperSource2Status))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = Top__DOT__upperROBData2;
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__upperSource2Status) 
                                                     >> 1U)))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__upperSource2Status) 
                                                     >> 1U)))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
        = ((0x1ffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
           | ((IData)(((0x200000U & vlSelf->Top__DOT__payload1[0U])
                        ? ((0x100000U & vlSelf->Top__DOT__payload1[0U])
                            ? (QData)((IData)(((vlSelf->Top__DOT__payload1[1U] 
                                                << 5U) 
                                               | (vlSelf->Top__DOT__payload1[0U] 
                                                  >> 0x1bU))))
                            : (((QData)((IData)(((vlSelf->Top__DOT__payload1[3U] 
                                                  << 0x1bU) 
                                                 | (vlSelf->Top__DOT__payload1[2U] 
                                                    >> 5U)))) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload1[1U] 
                                                              << 5U) 
                                                             | (vlSelf->Top__DOT__payload1[0U] 
                                                                >> 0x1bU))))))
                        : ((0x100000U & vlSelf->Top__DOT__payload1[0U])
                            ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload1[1U] 
                                                              << 5U) 
                                                             | (vlSelf->Top__DOT__payload1[0U] 
                                                                >> 0x1bU)))))
                            : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2)))))) 
              << 0x19U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[2U] 
        = (((IData)(((0x200000U & vlSelf->Top__DOT__payload1[0U])
                      ? ((0x100000U & vlSelf->Top__DOT__payload1[0U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload1[1U] 
                                              << 5U) 
                                             | (vlSelf->Top__DOT__payload1[0U] 
                                                >> 0x1bU))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload1[3U] 
                                                << 0x1bU) 
                                               | (vlSelf->Top__DOT__payload1[2U] 
                                                  >> 5U)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[1U] 
                                                            << 5U) 
                                                           | (vlSelf->Top__DOT__payload1[0U] 
                                                              >> 0x1bU))))))
                      : ((0x100000U & vlSelf->Top__DOT__payload1[0U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[1U] 
                                                            << 5U) 
                                                           | (vlSelf->Top__DOT__payload1[0U] 
                                                              >> 0x1bU)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2)))))) 
            >> 7U) | ((IData)((((0x200000U & vlSelf->Top__DOT__payload1[0U])
                                 ? ((0x100000U & vlSelf->Top__DOT__payload1[0U])
                                     ? (QData)((IData)(
                                                       ((vlSelf->Top__DOT__payload1[1U] 
                                                         << 5U) 
                                                        | (vlSelf->Top__DOT__payload1[0U] 
                                                           >> 0x1bU))))
                                     : (((QData)((IData)(
                                                         ((vlSelf->Top__DOT__payload1[3U] 
                                                           << 0x1bU) 
                                                          | (vlSelf->Top__DOT__payload1[2U] 
                                                             >> 5U)))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[1U] 
                                                            << 5U) 
                                                           | (vlSelf->Top__DOT__payload1[0U] 
                                                              >> 0x1bU))))))
                                 : ((0x100000U & vlSelf->Top__DOT__payload1[0U])
                                     ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[1U] 
                                                            << 5U) 
                                                           | (vlSelf->Top__DOT__payload1[0U] 
                                                              >> 0x1bU)))))
                                     : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                         << 0x20U) 
                                        | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2))))) 
                               >> 0x20U)) << 0x19U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[3U] 
        = ((IData)((((0x200000U & vlSelf->Top__DOT__payload1[0U])
                      ? ((0x100000U & vlSelf->Top__DOT__payload1[0U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload1[1U] 
                                              << 5U) 
                                             | (vlSelf->Top__DOT__payload1[0U] 
                                                >> 0x1bU))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload1[3U] 
                                                << 0x1bU) 
                                               | (vlSelf->Top__DOT__payload1[2U] 
                                                  >> 5U)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[1U] 
                                                            << 5U) 
                                                           | (vlSelf->Top__DOT__payload1[0U] 
                                                              >> 0x1bU))))))
                      : ((0x100000U & vlSelf->Top__DOT__payload1[0U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[1U] 
                                                            << 5U) 
                                                           | (vlSelf->Top__DOT__payload1[0U] 
                                                              >> 0x1bU)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2))))) 
                    >> 0x20U)) >> 7U);
    if ((0U != (3U & (vlSelf->Top__DOT__payload1[0U] 
                      >> 6U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
            = ((0x1ffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload1[3U] 
                                   << 0x1bU) | (vlSelf->Top__DOT__payload1[2U] 
                                                >> 5U))) 
                  << 0x19U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
            = ((0xfe000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload1[3U] 
                                   << 0x1bU) | (vlSelf->Top__DOT__payload1[2U] 
                                                >> 5U))) 
                  >> 7U));
    } else if ((0U != (7U & (vlSelf->Top__DOT__payload1[0U] 
                             >> 0xcU)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
            = ((0x1ffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
               | ((((vlSelf->Top__DOT__payload1[3U] 
                     << 0x1bU) | (vlSelf->Top__DOT__payload1[2U] 
                                  >> 5U)) + ((vlSelf->Top__DOT__payload1[1U] 
                                              << 5U) 
                                             | (vlSelf->Top__DOT__payload1[0U] 
                                                >> 0x1bU))) 
                  << 0x19U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
            = ((0xfe000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
               | ((((vlSelf->Top__DOT__payload1[3U] 
                     << 0x1bU) | (vlSelf->Top__DOT__payload1[2U] 
                                  >> 5U)) + ((vlSelf->Top__DOT__payload1[1U] 
                                              << 5U) 
                                             | (vlSelf->Top__DOT__payload1[0U] 
                                                >> 0x1bU))) 
                  >> 7U));
    } else if ((2U == (3U & (vlSelf->Top__DOT__payload1[0U] 
                             >> 0x12U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
            = ((0x1ffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
               | (Top__DOT__operandSelect__DOT__upperOperand2 
                  << 0x19U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
            = ((0xfe000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
               | (Top__DOT__operandSelect__DOT__upperOperand2 
                  >> 7U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
        = ((0xfe0007ffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
           | (0xfffff800U & ((0x1f00000U & (vlSelf->Top__DOT__payload1[0U] 
                                            >> 2U)) 
                             | ((0xfc000U & (vlSelf->Top__DOT__payload1[0U] 
                                             << 8U)) 
                                | (0x3800U & (vlSelf->Top__DOT__payload1[0U] 
                                              >> 1U))))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
        = ((0xfffff801U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
           | (0xfffffffeU & ((0x7c0U & (vlSelf->Top__DOT__payload1[0U] 
                                        >> 9U)) | (0x3eU 
                                                   & vlSelf->Top__DOT__payload1[0U]))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
        = ((0xfffffffeU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
           | ((1U & ((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->Top__DOT__redirect)))) 
              && (1U & vlSelf->Top__DOT__payload1[0U])));
}

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf);

VL_ATTR_COLD bool VTop___024root___eval_phase__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VTop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VTop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__resolvedInstruction1 = VL_RAND_RESET_Q(43);
    vlSelf->Top__DOT__resolvedInstruction2 = VL_RAND_RESET_Q(43);
    vlSelf->Top__DOT__triggerStore = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__nextFreeSlots = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__upperSource1Status = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__upperSource2Status = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__lowerSource1Status = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__lowerSource2Status = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__instructionConsumed1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__instructionConsumed2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__requestPC1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__requestPC2 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(101, vlSelf->Top__DOT__payload1);
    VL_RAND_RESET_W(98, vlSelf->Top__DOT__payload2);
    vlSelf->Top__DOT__instructionPacket1 = VL_RAND_RESET_Q(44);
    vlSelf->Top__DOT__instructionPacket2 = VL_RAND_RESET_Q(44);
    VL_RAND_RESET_W(121, vlSelf->Top__DOT__exPayload1);
    VL_RAND_RESET_W(118, vlSelf->Top__DOT__exPayload2);
    vlSelf->Top__DOT__resultPayload1 = VL_RAND_RESET_Q(43);
    vlSelf->Top__DOT__resultPayload2 = VL_RAND_RESET_Q(43);
    vlSelf->Top__DOT__redirect = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__redirectVector = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__redirect1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__redirect2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__instruction1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__instruction2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__programCounter = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__lowFetchData);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__highFetchData);
    vlSelf->Top__DOT__reorderBuffer__DOT__storeACK = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__reorderBuffer__DOT__retireCount = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__reorderBuffer__DOT__debugCycle = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        VL_RAND_RESET_W(76, vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer[__Vi0]);
    }
    vlSelf->Top__DOT__reorderBuffer__DOT__freeSlots = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__calculatedNextFreeSlots = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__outgoingStore = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 6; ++__Vi1) {
            vlSelf->Top__DOT__reorderBuffer__DOT__forwardGrid[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__registerFile__DOT__registerFile[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__registerFile__DOT__debugCycle = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(121, vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1);
    VL_RAND_RESET_W(118, vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2);
    vlSelf->Top__DOT__execute__DOT__result1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__result2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__upperOperand1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__upperOperand2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__lowerOperand1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__lowerOperand2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__issue1AgeTag = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__decodeIssue__DOT__issue2AgeTag = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(101, vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2);
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(101, vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1);
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(101, vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload);
    VL_RAND_RESET_W(98, vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload);
    vlSelf->Top__DOT__decodeIssue__DOT__IR1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__IR2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__PC1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__PC2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__postRedirectCounter = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__debugCycle = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__internalBadData = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__block1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__block2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonIllegal1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonIllegal2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonSlot1Memory = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonWawConflict = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonBadFetch = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonRobOneFree = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonRobFull = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonUpperLoadHazard = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonLowerLoadHazard = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__reasonBackwardDependency = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->Top__DOT__instructionMemory__DOT__memory[__Vi0]);
    }
    vlSelf->Top__DOT__instructionMemory__DOT__redirectAddress = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__instructionMemory__DOT__nextAddress = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
}
