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
            VL_FATAL_MT("Test/Subsystems/PipelineTest.sv", 6, "", "Settle region did not converge.");
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
    CData/*1:0*/ Top__DOT__nextFreeSlots;
    Top__DOT__nextFreeSlots = 0;
    CData/*0:0*/ Top__DOT__redirect2;
    Top__DOT__redirect2 = 0;
    CData/*3:0*/ Top__DOT__memoryQueue__DOT__unnamedblk1__DOT__memFreeSlotsTemp;
    Top__DOT__memoryQueue__DOT__unnamedblk1__DOT__memFreeSlotsTemp = 0;
    IData/*31:0*/ Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__shiftedLoadData;
    Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__shiftedLoadData = 0;
    CData/*7:0*/ Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadByte;
    Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadByte = 0;
    SData/*15:0*/ Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadHalf;
    Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadHalf = 0;
    CData/*1:0*/ Top__DOT__reorderBuffer__DOT__retireCount;
    Top__DOT__reorderBuffer__DOT__retireCount = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__redirectPointer;
    Top__DOT__reorderBuffer__DOT__redirectPointer = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__usedEntries;
    Top__DOT__reorderBuffer__DOT__usedEntries = 0;
    CData/*0:0*/ Top__DOT__reorderBuffer__DOT__moreThanOne;
    Top__DOT__reorderBuffer__DOT__moreThanOne = 0;
    CData/*1:0*/ Top__DOT__reorderBuffer__DOT__flushCount;
    Top__DOT__reorderBuffer__DOT__flushCount = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__flushDest1;
    Top__DOT__reorderBuffer__DOT__flushDest1 = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__flushDest2;
    Top__DOT__reorderBuffer__DOT__flushDest2 = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__flushDest3;
    Top__DOT__reorderBuffer__DOT__flushDest3 = 0;
    CData/*3:0*/ Top__DOT__reorderBuffer__DOT__minIndex1;
    Top__DOT__reorderBuffer__DOT__minIndex1 = 0;
    CData/*3:0*/ Top__DOT__reorderBuffer__DOT__minIndex2;
    Top__DOT__reorderBuffer__DOT__minIndex2 = 0;
    CData/*3:0*/ Top__DOT__reorderBuffer__DOT__minIndex3;
    Top__DOT__reorderBuffer__DOT__minIndex3 = 0;
    CData/*3:0*/ Top__DOT__reorderBuffer__DOT__minValue1;
    Top__DOT__reorderBuffer__DOT__minValue1 = 0;
    CData/*3:0*/ Top__DOT__reorderBuffer__DOT__minValue2;
    Top__DOT__reorderBuffer__DOT__minValue2 = 0;
    CData/*3:0*/ Top__DOT__reorderBuffer__DOT__minValue3;
    Top__DOT__reorderBuffer__DOT__minValue3 = 0;
    CData/*0:0*/ Top__DOT__reorderBuffer__DOT__found1;
    Top__DOT__reorderBuffer__DOT__found1 = 0;
    CData/*0:0*/ Top__DOT__reorderBuffer__DOT__found2;
    Top__DOT__reorderBuffer__DOT__found2 = 0;
    CData/*0:0*/ Top__DOT__reorderBuffer__DOT__found3;
    Top__DOT__reorderBuffer__DOT__found3 = 0;
    CData/*3:0*/ Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd;
    Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd = 0;
    CData/*0:0*/ Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 = 0;
    CData/*3:0*/ Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0;
    Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0 = 0;
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
    CData/*0:0*/ Top__DOT__execute__DOT__illegal2;
    Top__DOT__execute__DOT__illegal2 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__upperOperand1;
    Top__DOT__execute__DOT__upperOperand1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__upperOperand2;
    Top__DOT__execute__DOT__upperOperand2 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__lowerOperand1;
    Top__DOT__execute__DOT__lowerOperand1 = 0;
    IData/*31:0*/ Top__DOT__execute__DOT__lowerOperand2;
    Top__DOT__execute__DOT__lowerOperand2 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0;
    Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0;
    Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0;
    Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0 = 0;
    CData/*0:0*/ Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0;
    Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0 = 0;
    CData/*0:0*/ Top__DOT__decodeIssue__DOT__block1;
    Top__DOT__decodeIssue__DOT__block1 = 0;
    CData/*0:0*/ Top__DOT__decodeIssue__DOT__block2;
    Top__DOT__decodeIssue__DOT__block2 = 0;
    CData/*0:0*/ Top__DOT__decodeIssue__DOT__standardOp1;
    Top__DOT__decodeIssue__DOT__standardOp1 = 0;
    CData/*0:0*/ Top__DOT__decodeIssue__DOT__standardOp2;
    Top__DOT__decodeIssue__DOT__standardOp2 = 0;
    // Body
    vlSelf->Top__DOT__completedMemory = 0ULL;
    Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__shiftedLoadData 
        = VL_SHIFTR_III(32,32,32, (IData)((vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister 
                                           >> 1U)), 
                        VL_SHIFTL_III(32,32,32, (3U 
                                                 & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                    [0U][1U] 
                                                    >> 0xeU)), 3U));
    Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadByte 
        = (0xffU & Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__shiftedLoadData);
    Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadHalf 
        = (0xffffU & VL_SHIFTR_III(16,32,32, (IData)(
                                                     (vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister 
                                                      >> 1U)), 
                                   VL_SHIFTL_III(32,32,32, 
                                                 (1U 
                                                  & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                     [0U][1U] 
                                                     >> 0xfU)), 4U)));
    if (((1U == (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                       [0U][0U] >> 0xcU))) & (IData)(vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister))) {
        if ((0U == (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                          [0U][0U] >> 0xaU)))) {
            vlSelf->Top__DOT__completedMemory = ((0x3c00000003fULL 
                                                  & vlSelf->Top__DOT__completedMemory) 
                                                 | ((QData)((IData)(
                                                                    ((0x200U 
                                                                      & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                      [0U][0U])
                                                                      ? 
                                                                     (((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadByte) 
                                                                                >> 7U)))) 
                                                                       << 8U) 
                                                                      | (IData)(Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadByte))
                                                                      : (IData)(Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadByte)))) 
                                                    << 6U));
        } else if ((1U == (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                 [0U][0U] >> 0xaU)))) {
            vlSelf->Top__DOT__completedMemory = ((0x3c00000003fULL 
                                                  & vlSelf->Top__DOT__completedMemory) 
                                                 | ((QData)((IData)(
                                                                    ((0x200U 
                                                                      & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                      [0U][0U])
                                                                      ? 
                                                                     (((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadHalf) 
                                                                                >> 0xfU)))) 
                                                                       << 0x10U) 
                                                                      | (IData)(Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadHalf))
                                                                      : (IData)(Top__DOT__memoryQueue__DOT__unnamedblk2__DOT__loadHalf)))) 
                                                    << 6U));
        } else if ((3U == (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                 [0U][0U] >> 0xaU)))) {
            vlSelf->Top__DOT__completedMemory = ((0x3c00000003fULL 
                                                  & vlSelf->Top__DOT__completedMemory) 
                                                 | ((QData)((IData)((IData)(
                                                                            (vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister 
                                                                             >> 1U)))) 
                                                    << 6U));
        }
        vlSelf->Top__DOT__completedMemory = ((0x3fffffffffULL 
                                              & vlSelf->Top__DOT__completedMemory) 
                                             | ((QData)((IData)(
                                                                (0xfU 
                                                                 & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                 [0U][0U]))) 
                                                << 0x26U));
        vlSelf->Top__DOT__completedMemory = ((0x3ffffffffc0ULL 
                                              & vlSelf->Top__DOT__completedMemory) 
                                             | (IData)((IData)(
                                                               (1U 
                                                                | (0x3eU 
                                                                   & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                      [0U][0U] 
                                                                      >> 3U))))));
    }
    if ((0U == (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                      [0U][0U] >> 0xaU)))) {
        vlSelf->Top__DOT__memoryQueue__DOT__byteSelectTransform 
            = (0xfU & ((IData)(1U) << (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                             [0U][1U] 
                                             >> 0xeU))));
    } else if ((1U == (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [0U][0U] >> 0xaU)))) {
        vlSelf->Top__DOT__memoryQueue__DOT__byteSelectTransform 
            = (0xfU & ((IData)(3U) << (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                             [0U][1U] 
                                             >> 0xeU))));
    } else if ((3U == (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [0U][0U] >> 0xaU)))) {
        vlSelf->Top__DOT__memoryQueue__DOT__byteSelectTransform = 0xfU;
    }
    if ((0U != (0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                         >> 2U)))) {
        vlSelf->Top__DOT__upperSourceData1 = vlSelf->Top__DOT__registerFile__DOT__registerFile
            [(0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                       >> 2U))];
        vlSelf->Top__DOT__upperSource1Status = ((1U 
                                                 & (IData)(vlSelf->Top__DOT__upperSource1Status)) 
                                                | ((0x20U 
                                                    & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__payload1[2U] 
                                                           >> 2U))] 
                                                       << 4U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                         [
                                                         (0x1fU 
                                                          & (vlSelf->Top__DOT__payload1[2U] 
                                                             >> 2U))] 
                                                         >> 1U))));
        vlSelf->Top__DOT__upperSource1Status = ((0x3eU 
                                                 & (IData)(vlSelf->Top__DOT__upperSource1Status)) 
                                                | (1U 
                                                   & vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT__payload1[2U] 
                                                       >> 2U))]));
    } else {
        vlSelf->Top__DOT__upperSourceData1 = 0U;
        vlSelf->Top__DOT__upperSource1Status = (0x20U 
                                                | (IData)(vlSelf->Top__DOT__upperSource1Status));
        vlSelf->Top__DOT__upperSource1Status = (1U 
                                                | (IData)(vlSelf->Top__DOT__upperSource1Status));
    }
    if ((0U != (0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                         >> 7U)))) {
        vlSelf->Top__DOT__upperSourceData2 = vlSelf->Top__DOT__registerFile__DOT__registerFile
            [(0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                       >> 7U))];
        vlSelf->Top__DOT__upperSource2Status = ((1U 
                                                 & (IData)(vlSelf->Top__DOT__upperSource2Status)) 
                                                | ((0x20U 
                                                    & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__payload1[2U] 
                                                           >> 7U))] 
                                                       << 4U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                         [
                                                         (0x1fU 
                                                          & (vlSelf->Top__DOT__payload1[2U] 
                                                             >> 7U))] 
                                                         >> 1U))));
        vlSelf->Top__DOT__upperSource2Status = ((0x3eU 
                                                 & (IData)(vlSelf->Top__DOT__upperSource2Status)) 
                                                | (1U 
                                                   & vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT__payload1[2U] 
                                                       >> 7U))]));
    } else {
        vlSelf->Top__DOT__upperSourceData2 = 0U;
        vlSelf->Top__DOT__upperSource2Status = (0x20U 
                                                | (IData)(vlSelf->Top__DOT__upperSource2Status));
        vlSelf->Top__DOT__upperSource2Status = (1U 
                                                | (IData)(vlSelf->Top__DOT__upperSource2Status));
    }
    if ((0U != (0x1fU & ((vlSelf->Top__DOT__payload2[2U] 
                          << 1U) | (vlSelf->Top__DOT__payload2[1U] 
                                    >> 0x1fU))))) {
        vlSelf->Top__DOT__lowerSourceData1 = vlSelf->Top__DOT__registerFile__DOT__registerFile
            [(0x1fU & ((vlSelf->Top__DOT__payload2[2U] 
                        << 1U) | (vlSelf->Top__DOT__payload2[1U] 
                                  >> 0x1fU)))];
        vlSelf->Top__DOT__lowerSource1Status = ((1U 
                                                 & (IData)(vlSelf->Top__DOT__lowerSource1Status)) 
                                                | ((0x20U 
                                                    & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & ((vlSelf->Top__DOT__payload2[2U] 
                                                            << 1U) 
                                                           | (vlSelf->Top__DOT__payload2[1U] 
                                                              >> 0x1fU)))] 
                                                       << 4U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                         [
                                                         (0x1fU 
                                                          & ((vlSelf->Top__DOT__payload2[2U] 
                                                              << 1U) 
                                                             | (vlSelf->Top__DOT__payload2[1U] 
                                                                >> 0x1fU)))] 
                                                         >> 1U))));
        vlSelf->Top__DOT__lowerSource1Status = ((0x3eU 
                                                 & (IData)(vlSelf->Top__DOT__lowerSource1Status)) 
                                                | (1U 
                                                   & vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [
                                                   (0x1fU 
                                                    & ((vlSelf->Top__DOT__payload2[2U] 
                                                        << 1U) 
                                                       | (vlSelf->Top__DOT__payload2[1U] 
                                                          >> 0x1fU)))]));
    } else {
        vlSelf->Top__DOT__lowerSourceData1 = 0U;
        vlSelf->Top__DOT__lowerSource1Status = (0x20U 
                                                | (IData)(vlSelf->Top__DOT__lowerSource1Status));
        vlSelf->Top__DOT__lowerSource1Status = (1U 
                                                | (IData)(vlSelf->Top__DOT__lowerSource1Status));
    }
    if ((0U != (0x1fU & (vlSelf->Top__DOT__payload2[2U] 
                         >> 4U)))) {
        vlSelf->Top__DOT__lowerSourceData2 = vlSelf->Top__DOT__registerFile__DOT__registerFile
            [(0x1fU & (vlSelf->Top__DOT__payload2[2U] 
                       >> 4U))];
        vlSelf->Top__DOT__lowerSource2Status = ((1U 
                                                 & (IData)(vlSelf->Top__DOT__lowerSource2Status)) 
                                                | ((0x20U 
                                                    & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__payload2[2U] 
                                                           >> 4U))] 
                                                       << 4U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                         [
                                                         (0x1fU 
                                                          & (vlSelf->Top__DOT__payload2[2U] 
                                                             >> 4U))] 
                                                         >> 1U))));
        vlSelf->Top__DOT__lowerSource2Status = ((0x3eU 
                                                 & (IData)(vlSelf->Top__DOT__lowerSource2Status)) 
                                                | (1U 
                                                   & vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT__payload2[2U] 
                                                       >> 4U))]));
    } else {
        vlSelf->Top__DOT__lowerSourceData2 = 0U;
        vlSelf->Top__DOT__lowerSource2Status = (0x20U 
                                                | (IData)(vlSelf->Top__DOT__lowerSource2Status));
        vlSelf->Top__DOT__lowerSource2Status = (1U 
                                                | (IData)(vlSelf->Top__DOT__lowerSource2Status));
    }
    vlSelf->Top__DOT__reorderBuffer__DOT__entries = 
        (0x1fU & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer) 
                  - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[3U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
        = ((0xfffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
           | (vlSelf->Top__DOT__decodeIssue__DOT__PC2 
              << 0xcU));
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[3U] 
        = (vlSelf->Top__DOT__decodeIssue__DOT__PC2 
           >> 0x14U);
    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 = 0U;
    if ((0x40U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((0x20U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((1U & (~ vlSelf->Top__DOT__decodeIssue__DOT__IR2))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                            vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                                = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                            >> 7U));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                = (0x10000000U | (0xe7ffffffU 
                                                  & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                = (0x2000U | (0xffff9fffU 
                                              & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                                = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                                   | (0xfffffffcU & 
                                      (((- (IData)(
                                                   (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                    >> 0x1fU))) 
                                        << 0x16U) | 
                                       ((0x3fc000U 
                                         & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                            << 2U)) 
                                        | ((0x2000U 
                                            & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                               >> 7U)) 
                                           | (0x1ff8U 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                 >> 0x12U)))))));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                                   | (3U & ((- (IData)(
                                                       (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                        >> 0x1fU))) 
                                            >> 0xaU)));
                        } else {
                            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                        }
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                            = ((0xffffff83U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                               | (0x7cU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                           >> 0xdU)));
                        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                            = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                        >> 7U));
                        if ((0U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                          >> 0xcU)))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                        }
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x8000000U | (0xe7ffffffU 
                                             & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x4000U | (0xffff9fffU 
                                          & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                            = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                               | (0xfffffffcU & (((- (IData)(
                                                             (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                              >> 0x1fU))) 
                                                  << 0xeU) 
                                                 | (0x3ffcU 
                                                    & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                       >> 0x12U)))));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                            = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                               | (3U & ((- (IData)(
                                                   (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                    >> 0x1fU))) 
                                        >> 0x12U)));
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                        = ((0xfffff003U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                           | (0xffcU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                        >> 0xdU)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0xe7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                        = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                           | (0xfffffffcU & (((- (IData)(
                                                         (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                          >> 0x1fU))) 
                                              << 0xfU) 
                                             | ((0x4000U 
                                                 & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                    >> 0x11U)) 
                                                | ((0x2000U 
                                                    & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                       << 6U)) 
                                                   | ((0x1f80U 
                                                       & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                          >> 0x12U)) 
                                                      | (0x78U 
                                                         & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                            >> 5U))))))));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                        = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                           | (3U & ((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0x1fU))) 
                                    >> 0x11U)));
                    if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = ((0xffc7ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                               | (((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                    ? ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                        ? 6U : 5U) : 
                                   ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                     ? 4U : 3U)) << 0x13U));
                    } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = ((0xffc7ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                               | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                    ? 2U : 1U) << 0x13U));
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else if ((0x20U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                            = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                        >> 7U));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x18000000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                            = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                               | (0xffffc000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                 << 2U)));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                            = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                               | (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                  >> 0x1eU));
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                        = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                    >> 7U));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                        = ((0xfffff003U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                           | (0xffcU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                        >> 0xdU)));
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
                            = ((0xfff87fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
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
                                  << 0xfU));
                    } else if ((2U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0xcU))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x40000U | (0xfff87fffU 
                                           & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    } else if ((3U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0xcU))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x48000U | (0xfff87fffU 
                                           & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                    = ((0xfffff003U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                       | (0xffcU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                    >> 0xdU)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = (0x8000000U | (0xe7ffffffU & 
                                     vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                    = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                       | (0xfffffffcU & (((- (IData)(
                                                     (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                      >> 0x1fU))) 
                                          << 0xeU) 
                                         | ((0x3f80U 
                                             & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                >> 0x12U)) 
                                            | (0x7cU 
                                               & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                  >> 5U))))));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                    = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                       | (3U & ((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                            >> 0x1fU))) 
                                >> 0x12U)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = (0x4000000U | (0xf9ffffffU & 
                                     vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                if ((0U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                  >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0xfe7fffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                } else if ((1U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                         >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0x800000U | (0xfe7fffffU 
                                        & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                } else if ((2U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                         >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0x1800000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                        = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                    >> 7U));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0x10000000U | (0xe7ffffffU 
                                          & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                        = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                           | (0xffffc000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                             << 2U)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                        = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                           | (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                              >> 0x1eU));
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                    = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                >> 7U));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                    = ((0xffffff83U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                       | (0x7cU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                   >> 0xdU)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = (0x8000000U | (0xe7ffffffU & 
                                     vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                    = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                       | (0xfffffffcU & (((- (IData)(
                                                     (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                      >> 0x1fU))) 
                                          << 0xeU) 
                                         | (0x3ffcU 
                                            & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                               >> 0x12U)))));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                    = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                       | (3U & ((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                            >> 0x1fU))) 
                                >> 0x12U)));
                if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = ((0xfff87fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                               | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                    ? 2U : 3U) << 0xfU));
                    } else if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                        if ((0U == (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                    >> 0x19U))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                = (0x30000U | (0xfff87fffU 
                                               & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                        } else if ((0x20U == (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                              >> 0x19U))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                = (0x38000U | (0xfff87fffU 
                                               & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                        } else {
                            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                        }
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x20000U | (0xfff87fffU 
                                           & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    }
                } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = ((0xfff87fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                           | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                ? 9U : 8U) << 0xfU));
                } else if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((0U == (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                >> 0x19U))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                            = (0x28000U | (0xfff87fffU 
                                           & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0xfff87fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    if ((0U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                      >> 0xcU)))) {
                        if ((1U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                          >> 0xcU)))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                        }
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
    } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
        if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
            vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 
                = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                            >> 7U));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                = ((0xffffff83U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                   | (0x7cU & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                               >> 0xdU)));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                = (0x8000000U | (0xe7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U]) 
                   | (0xfffffffcU & (((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                  >> 0x1fU))) 
                                      << 0xeU) | (0x3ffcU 
                                                  & (vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                                     >> 0x12U)))));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U]) 
                   | (3U & ((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR2 
                                        >> 0x1fU))) 
                            >> 0x12U)));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                = (0x2000000U | (0xf9ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]));
            if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = ((0xfe3fffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                           | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                                ? 2U : 0U) << 0x16U));
                }
            } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                        = (0x1c00000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                    = ((0xfe3fffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]) 
                       | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR2)
                            ? 3U : 1U) << 0x16U));
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
        }
    } else {
        vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = 1U;
    }
    if (vlSelf->Top__DOT__decodeIssue__DOT__illegal2) {
        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
            = (0xf9ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U]);
    }
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[3U] = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
        = ((0xfffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
           | (vlSelf->Top__DOT__decodeIssue__DOT__PC1 
              << 0xcU));
    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[3U] 
        = (vlSelf->Top__DOT__decodeIssue__DOT__PC1 
           >> 0x14U);
    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 = 0U;
    if ((0x40U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((0x20U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((1U & (~ vlSelf->Top__DOT__decodeIssue__DOT__IR1))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                            vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                                = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                            >> 7U));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                = (0x10000000U | (0xe7ffffffU 
                                                  & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                = (0x2000U | (0xffff9fffU 
                                              & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                                = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                                   | (0xfffffffcU & 
                                      (((- (IData)(
                                                   (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                    >> 0x1fU))) 
                                        << 0x16U) | 
                                       ((0x3fc000U 
                                         & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                            << 2U)) 
                                        | ((0x2000U 
                                            & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                               >> 7U)) 
                                           | (0x1ff8U 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                 >> 0x12U)))))));
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                                = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                                   | (3U & ((- (IData)(
                                                       (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                        >> 0x1fU))) 
                                            >> 0xaU)));
                        } else {
                            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                        }
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                            = ((0xffffff83U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                               | (0x7cU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                           >> 0xdU)));
                        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                            = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                        >> 7U));
                        if ((0U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                          >> 0xcU)))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                        }
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x8000000U | (0xe7ffffffU 
                                             & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x4000U | (0xffff9fffU 
                                          & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                            = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                               | (0xfffffffcU & (((- (IData)(
                                                             (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                              >> 0x1fU))) 
                                                  << 0xeU) 
                                                 | (0x3ffcU 
                                                    & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                       >> 0x12U)))));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                            = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                               | (3U & ((- (IData)(
                                                   (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                    >> 0x1fU))) 
                                        >> 0x12U)));
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                        = ((0xfffff003U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                           | (0xffcU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                        >> 0xdU)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0xe7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                        = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                           | (0xfffffffcU & (((- (IData)(
                                                         (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                          >> 0x1fU))) 
                                              << 0xfU) 
                                             | ((0x4000U 
                                                 & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                    >> 0x11U)) 
                                                | ((0x2000U 
                                                    & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                       << 6U)) 
                                                   | ((0x1f80U 
                                                       & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                          >> 0x12U)) 
                                                      | (0x78U 
                                                         & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                            >> 5U))))))));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                        = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                           | (3U & ((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0x1fU))) 
                                    >> 0x11U)));
                    if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = ((0xffc7ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                               | (((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                    ? ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                        ? 6U : 5U) : 
                                   ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                     ? 4U : 3U)) << 0x13U));
                    } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = ((0xffc7ffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                               | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                    ? 2U : 1U) << 0x13U));
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else if ((0x20U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                            = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                        >> 7U));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x18000000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                            = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                               | (0xffffc000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                 << 2U)));
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                            = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                               | (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                  >> 0x1eU));
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                        = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                    >> 7U));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                        = ((0xfffff003U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                           | (0xffcU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                        >> 0xdU)));
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
                            = ((0xfff87fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
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
                                  << 0xfU));
                    } else if ((2U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0xcU))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x40000U | (0xfff87fffU 
                                           & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    } else if ((3U == ((0x3f8U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                  >> 0x16U)) 
                                       | (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0xcU))))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x48000U | (0xfff87fffU 
                                           & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                    = ((0xfffff003U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                       | (0xffcU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                    >> 0xdU)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = (0x8000000U | (0xe7ffffffU & 
                                     vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                    = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                       | (0xfffffffcU & (((- (IData)(
                                                     (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                      >> 0x1fU))) 
                                          << 0xeU) 
                                         | ((0x3f80U 
                                             & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                >> 0x12U)) 
                                            | (0x7cU 
                                               & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                  >> 5U))))));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                    = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                       | (3U & ((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                            >> 0x1fU))) 
                                >> 0x12U)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = (0x4000000U | (0xf9ffffffU & 
                                     vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                if ((0U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                  >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0xfe7fffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                } else if ((1U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                         >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0x800000U | (0xfe7fffffU 
                                        & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                } else if ((2U == (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                         >> 0xcU)))) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0x1800000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else if ((0x10U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                        = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                    >> 7U));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0x10000000U | (0xe7ffffffU 
                                          & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                        = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                           | (0xffffc000U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                             << 2U)));
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                        = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                           | (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                              >> 0x1eU));
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                    = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                >> 7U));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                    = ((0xffffff83U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                       | (0x7cU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                   >> 0xdU)));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = (0x8000000U | (0xe7ffffffU & 
                                     vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                    = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                       | (0xfffffffcU & (((- (IData)(
                                                     (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                      >> 0x1fU))) 
                                          << 0xeU) 
                                         | (0x3ffcU 
                                            & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                               >> 0x12U)))));
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                    = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                       | (3U & ((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                            >> 0x1fU))) 
                                >> 0x12U)));
                if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = ((0xfff87fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                               | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                    ? 2U : 3U) << 0xfU));
                    } else if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                        if ((0U == (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                    >> 0x19U))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                = (0x30000U | (0xfff87fffU 
                                               & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                        } else if ((0x20U == (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                              >> 0x19U))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                = (0x38000U | (0xfff87fffU 
                                               & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                        } else {
                            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                        }
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x20000U | (0xfff87fffU 
                                           & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    }
                } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = ((0xfff87fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                           | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                ? 9U : 8U) << 0xfU));
                } else if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((0U == (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                >> 0x19U))) {
                        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                            = (0x28000U | (0xfff87fffU 
                                           & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
                    } else {
                        vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0xfff87fffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else if ((8U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    if ((0U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                      >> 0xcU)))) {
                        if ((1U != (7U & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                          >> 0xcU)))) {
                            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                        }
                    }
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else if ((4U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
    } else if ((2U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
        if ((1U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
            vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 
                = (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                            >> 7U));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                = ((0xffffff83U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                   | (0x7cU & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                               >> 0xdU)));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                = (0x8000000U | (0xe7ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                = ((3U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U]) 
                   | (0xfffffffcU & (((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                  >> 0x1fU))) 
                                      << 0xeU) | (0x3ffcU 
                                                  & (vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                                     >> 0x12U)))));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U]) 
                   | (3U & ((- (IData)((vlSelf->Top__DOT__decodeIssue__DOT__IR1 
                                        >> 0x1fU))) 
                            >> 0x12U)));
            vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                = (0x2000000U | (0xf9ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]));
            if ((0x4000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = ((0xfe3fffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                           | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                                ? 2U : 0U) << 0x16U));
                }
            } else if ((0x2000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                if ((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)) {
                    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
                } else {
                    vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                        = (0x1c00000U | vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
                }
            } else {
                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                    = ((0xfe3fffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]) 
                       | (((0x1000U & vlSelf->Top__DOT__decodeIssue__DOT__IR1)
                            ? 3U : 1U) << 0x16U));
            }
        } else {
            vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
        }
    } else {
        vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = 1U;
    }
    if (vlSelf->Top__DOT__decodeIssue__DOT__illegal1) {
        vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 = 0U;
        vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
            = (0xf9ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U]);
    }
    Top__DOT__execute__DOT__upperOperand1 = ((vlSelf->Top__DOT__exPayload1[3U] 
                                              << 8U) 
                                             | (vlSelf->Top__DOT__exPayload1[2U] 
                                                >> 0x18U));
    Top__DOT__execute__DOT__upperOperand2 = ((vlSelf->Top__DOT__exPayload1[2U] 
                                              << 8U) 
                                             | (vlSelf->Top__DOT__exPayload1[1U] 
                                                >> 0x18U));
    vlSelf->Top__DOT__execute__DOT__result1 = 0U;
    if ((0x40000U & vlSelf->Top__DOT__exPayload1[0U])) {
        if ((1U & (~ (vlSelf->Top__DOT__exPayload1[0U] 
                      >> 0x11U)))) {
            if ((1U & (~ (vlSelf->Top__DOT__exPayload1[0U] 
                          >> 0x10U)))) {
                vlSelf->Top__DOT__execute__DOT__result1 
                    = ((0x8000U & vlSelf->Top__DOT__exPayload1[0U])
                        ? ((Top__DOT__execute__DOT__upperOperand1 
                            < Top__DOT__execute__DOT__upperOperand2)
                            ? 1U : 0U) : (VL_LTS_III(32, Top__DOT__execute__DOT__upperOperand1, Top__DOT__execute__DOT__upperOperand2)
                                           ? 1U : 0U));
            }
        }
    } else {
        vlSelf->Top__DOT__execute__DOT__result1 = (
                                                   (0x20000U 
                                                    & vlSelf->Top__DOT__exPayload1[0U])
                                                    ? 
                                                   ((0x10000U 
                                                     & vlSelf->Top__DOT__exPayload1[0U])
                                                     ? 
                                                    ((0x8000U 
                                                      & vlSelf->Top__DOT__exPayload1[0U])
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, Top__DOT__execute__DOT__upperOperand1, 
                                                                    (0x1fU 
                                                                     & Top__DOT__execute__DOT__upperOperand2))
                                                      : 
                                                     (Top__DOT__execute__DOT__upperOperand1 
                                                      >> 
                                                      (0x1fU 
                                                       & Top__DOT__execute__DOT__upperOperand2)))
                                                     : 
                                                    ((0x8000U 
                                                      & vlSelf->Top__DOT__exPayload1[0U])
                                                      ? 
                                                     (Top__DOT__execute__DOT__upperOperand1 
                                                      << 
                                                      (0x1fU 
                                                       & Top__DOT__execute__DOT__upperOperand2))
                                                      : 
                                                     (Top__DOT__execute__DOT__upperOperand1 
                                                      ^ Top__DOT__execute__DOT__upperOperand2)))
                                                    : 
                                                   ((0x10000U 
                                                     & vlSelf->Top__DOT__exPayload1[0U])
                                                     ? 
                                                    ((0x8000U 
                                                      & vlSelf->Top__DOT__exPayload1[0U])
                                                      ? 
                                                     (Top__DOT__execute__DOT__upperOperand1 
                                                      | Top__DOT__execute__DOT__upperOperand2)
                                                      : 
                                                     (Top__DOT__execute__DOT__upperOperand1 
                                                      & Top__DOT__execute__DOT__upperOperand2))
                                                     : 
                                                    ((0x8000U 
                                                      & vlSelf->Top__DOT__exPayload1[0U])
                                                      ? 
                                                     (Top__DOT__execute__DOT__upperOperand1 
                                                      - Top__DOT__execute__DOT__upperOperand2)
                                                      : 
                                                     (Top__DOT__execute__DOT__upperOperand1 
                                                      + Top__DOT__execute__DOT__upperOperand2))));
    }
    vlSelf->Top__DOT__memBusOut[0U] = 0U;
    vlSelf->Top__DOT__memBusOut[1U] = 0U;
    vlSelf->Top__DOT__memBusOut[2U] = 0U;
    if ((1U == (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                      [0U][0U] >> 0xcU)))) {
        vlSelf->Top__DOT__memBusOut[1U] = ((0x7fU & 
                                            vlSelf->Top__DOT__memBusOut[1U]) 
                                           | (0xffffff80U 
                                              & ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [0U][2U] 
                                                  << 0x19U) 
                                                 | (0x1ffff80U 
                                                    & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                       [0U][1U] 
                                                       >> 7U)))));
        vlSelf->Top__DOT__memBusOut[2U] = (0x7fU & 
                                           (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                            [0U][2U] 
                                            >> 7U));
        vlSelf->Top__DOT__memBusOut[0U] = (3U | ((0xffffff80U 
                                                  & vlSelf->Top__DOT__memBusOut[0U]) 
                                                 | ((IData)(vlSelf->Top__DOT__memoryQueue__DOT__byteSelectTransform) 
                                                    << 2U)));
    }
    if ((2U == (3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                      [0U][0U] >> 0xcU)))) {
        vlSelf->Top__DOT__memBusOut[1U] = ((0x7fU & 
                                            vlSelf->Top__DOT__memBusOut[1U]) 
                                           | (0xffffff80U 
                                              & ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [0U][2U] 
                                                  << 0x19U) 
                                                 | (0x1ffff80U 
                                                    & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                       [0U][1U] 
                                                       >> 7U)))));
        vlSelf->Top__DOT__memBusOut[2U] = (0x7fU & 
                                           (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                            [0U][2U] 
                                            >> 7U));
        vlSelf->Top__DOT__memBusOut[0U] = ((1U & vlSelf->Top__DOT__memBusOut[0U]) 
                                           | ((IData)(
                                                      (((QData)((IData)(
                                                                        VL_SHIFTL_III(32,32,32, 
                                                                                ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                                [0U][1U] 
                                                                                << 0x12U) 
                                                                                | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                                [0U][0U] 
                                                                                >> 0xeU)), 
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                (3U 
                                                                                & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                                [0U][1U] 
                                                                                >> 0xeU)), 3U)))) 
                                                        << 6U) 
                                                       | (QData)((IData)(
                                                                         (0x21U 
                                                                          | ((IData)(vlSelf->Top__DOT__memoryQueue__DOT__byteSelectTransform) 
                                                                             << 1U)))))) 
                                              << 1U));
        vlSelf->Top__DOT__memBusOut[1U] = ((0xffffff80U 
                                            & vlSelf->Top__DOT__memBusOut[1U]) 
                                           | (((IData)(
                                                       (((QData)((IData)(
                                                                         VL_SHIFTL_III(32,32,32, 
                                                                                ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                                [0U][1U] 
                                                                                << 0x12U) 
                                                                                | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                                [0U][0U] 
                                                                                >> 0xeU)), 
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                (3U 
                                                                                & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                                [0U][1U] 
                                                                                >> 0xeU)), 3U)))) 
                                                         << 6U) 
                                                        | (QData)((IData)(
                                                                          (0x21U 
                                                                           | ((IData)(vlSelf->Top__DOT__memoryQueue__DOT__byteSelectTransform) 
                                                                              << 1U)))))) 
                                               >> 0x1fU) 
                                              | ((IData)(
                                                         ((((QData)((IData)(
                                                                            VL_SHIFTL_III(32,32,32, 
                                                                                ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                                [0U][1U] 
                                                                                << 0x12U) 
                                                                                | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                                [0U][0U] 
                                                                                >> 0xeU)), 
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                (3U 
                                                                                & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                                                [0U][1U] 
                                                                                >> 0xeU)), 3U)))) 
                                                            << 6U) 
                                                           | (QData)((IData)(
                                                                             (0x21U 
                                                                              | ((IData)(vlSelf->Top__DOT__memoryQueue__DOT__byteSelectTransform) 
                                                                                << 1U))))) 
                                                          >> 0x20U)) 
                                                 << 1U)));
        vlSelf->Top__DOT__memBusOut[0U] = (1U | vlSelf->Top__DOT__memBusOut[0U]);
    }
    vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status 
        = (0x3fU & ((0x80U & vlSelf->Top__DOT__payload2[0U])
                     ? ((vlSelf->Top__DOT__payload2[0U] 
                         << 0x1fU) | (vlSelf->Top__DOT__payload2[0U] 
                                      >> 1U)) : (IData)(vlSelf->Top__DOT__lowerSource1Status)));
    vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status 
        = (0x3fU & ((0x100U & vlSelf->Top__DOT__payload1[0U])
                     ? ((vlSelf->Top__DOT__payload1[0U] 
                         << 0x1fU) | (vlSelf->Top__DOT__payload1[0U] 
                                      >> 1U)) : (IData)(vlSelf->Top__DOT__upperSource2Status)));
    vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status 
        = (0x3fU & ((0x80U & vlSelf->Top__DOT__payload1[0U])
                     ? ((vlSelf->Top__DOT__payload1[0U] 
                         << 0x1fU) | (vlSelf->Top__DOT__payload1[0U] 
                                      >> 1U)) : (IData)(vlSelf->Top__DOT__upperSource1Status)));
    vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status 
        = (0x3fU & ((0x100U & vlSelf->Top__DOT__payload2[0U])
                     ? ((vlSelf->Top__DOT__payload2[0U] 
                         << 0x1fU) | (vlSelf->Top__DOT__payload2[0U] 
                                      >> 1U)) : (IData)(vlSelf->Top__DOT__lowerSource2Status)));
    vlSelf->Top__DOT__resolvedInstruction1 = 0ULL;
    vlSelf->Top__DOT__resolvedInstruction2 = 0ULL;
    Top__DOT__reorderBuffer__DOT__retireCount = 0U;
    if ((((1U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)) 
          & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
             [(0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
             | ((0U == (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                 [(0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                                 >> 6U))) & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                             [(0xfU 
                                               & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                                             >> 1U)))) 
         & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
            [(0xfU & ((IData)(1U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
            | ((0U == (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                [(0xfU & ((IData)(1U) 
                                          + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                >> 6U))) & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [(0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                            >> 1U))))) {
        if (((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                              [(0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                              >> 6U))) & ((0x1fU & 
                                           (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [(0xfU 
                                              & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                                            >> 6U)) 
                                          == (0x1fU 
                                              & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                 [(0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                                 >> 6U))))) {
            vlSelf->Top__DOT__resolvedInstruction1 
                = ((0x3ffffffffe1ULL & vlSelf->Top__DOT__resolvedInstruction1) 
                   | ((QData)((IData)((0xfU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                               [(0xfU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                               >> 2U)))) 
                      << 1U));
            vlSelf->Top__DOT__resolvedInstruction1 
                = ((0x3ffULL & vlSelf->Top__DOT__resolvedInstruction1) 
                   | ((QData)((IData)(((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(1U) 
                                                  + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][1U] 
                                        << 0x15U) | 
                                       (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(1U) 
                                                  + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                        >> 0xbU)))) 
                      << 0xaU));
            vlSelf->Top__DOT__resolvedInstruction1 
                = ((0x3fffffffc1fULL & vlSelf->Top__DOT__resolvedInstruction1) 
                   | ((QData)((IData)((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [(0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                                >> 6U)))) 
                      << 5U));
            vlSelf->Top__DOT__resolvedInstruction1 
                = (1ULL | vlSelf->Top__DOT__resolvedInstruction1);
        } else if ((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                    [(0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                                    >> 6U)))) {
            vlSelf->Top__DOT__resolvedInstruction1 
                = (1ULL | (0x3fffffffffeULL & (((QData)((IData)(
                                                                vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                [
                                                                (0xfU 
                                                                 & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][1U])) 
                                                << 0x1fU) 
                                               | (0x7ffffffffffffffeULL 
                                                  & ((QData)((IData)(
                                                                     vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                     [
                                                                     (0xfU 
                                                                      & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U])) 
                                                     >> 1U)))));
        }
        if ((1U & (~ ((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                       [(0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                                       >> 6U))) & (
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                       [
                                                       (0xfU 
                                                        & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                                                       >> 6U)) 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                       [
                                                       (0xfU 
                                                        & ((IData)(1U) 
                                                           + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                                       >> 6U))))))) {
            if ((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                 [(0xfU & ((IData)(1U) 
                                           + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                 >> 6U)))) {
                vlSelf->Top__DOT__resolvedInstruction2 
                    = ((0x3ffffffffe1ULL & vlSelf->Top__DOT__resolvedInstruction2) 
                       | ((QData)((IData)((0xfU & (
                                                   vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                   [
                                                   (0xfU 
                                                    & ((IData)(1U) 
                                                       + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                                   >> 2U)))) 
                          << 1U));
                vlSelf->Top__DOT__resolvedInstruction2 
                    = ((0x3ffULL & vlSelf->Top__DOT__resolvedInstruction2) 
                       | ((QData)((IData)(((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [(0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][1U] 
                                            << 0x15U) 
                                           | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                              [(0xfU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                              >> 0xbU)))) 
                          << 0xaU));
                vlSelf->Top__DOT__resolvedInstruction2 
                    = ((0x3fffffffc1fULL & vlSelf->Top__DOT__resolvedInstruction2) 
                       | ((QData)((IData)((0x1fU & 
                                           (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [(0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)))][0U] 
                                            >> 6U)))) 
                          << 5U));
                vlSelf->Top__DOT__resolvedInstruction2 
                    = (1ULL | vlSelf->Top__DOT__resolvedInstruction2);
            }
        }
        Top__DOT__reorderBuffer__DOT__retireCount = 2U;
    } else if (((0U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)) 
                & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                   [(0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                   | ((0U == (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                       [(0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                                       >> 6U))) & (
                                                   vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                   [
                                                   (0xfU 
                                                    & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                                                   >> 1U))))) {
        if ((0U != (0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [(0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U] 
                             >> 6U)))) {
            vlSelf->Top__DOT__resolvedInstruction1 
                = (1ULL | (0x3fffffffffeULL & (((QData)((IData)(
                                                                vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                [
                                                                (0xfU 
                                                                 & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][1U])) 
                                                << 0x1fU) 
                                               | (0x7ffffffffffffffeULL 
                                                  & ((QData)((IData)(
                                                                     vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                                     [
                                                                     (0xfU 
                                                                      & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer))][0U])) 
                                                     >> 1U)))));
        }
        Top__DOT__reorderBuffer__DOT__retireCount = 1U;
    }
    if ((0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) {
        vlSelf->Top__DOT__oldLowerStatus = ((1U & (IData)(vlSelf->Top__DOT__oldLowerStatus)) 
                                            | ((0x20U 
                                                & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2] 
                                                   << 4U)) 
                                               | (0x1eU 
                                                  & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                     [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2] 
                                                     >> 1U))));
        vlSelf->Top__DOT__oldLowerStatus = ((0x3eU 
                                             & (IData)(vlSelf->Top__DOT__oldLowerStatus)) 
                                            | (1U & 
                                               vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                               [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2]));
    } else {
        vlSelf->Top__DOT__oldLowerStatus = (0x20U | (IData)(vlSelf->Top__DOT__oldLowerStatus));
        vlSelf->Top__DOT__oldLowerStatus = (1U | (IData)(vlSelf->Top__DOT__oldLowerStatus));
    }
    vlSelf->Top__DOT__destRegLoad2 = ((0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)) 
                                      && (1U & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                 [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2] 
                                                 >> 6U) 
                                                & (~ 
                                                   (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                    [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2] 
                                                    >> 1U)))));
    vlSelf->Top__DOT__decodeIssue__DOT__staleVector2 = 0U;
    if (((0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                   >> 2U)) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) {
        vlSelf->Top__DOT__decodeIssue__DOT__staleVector2 
            = (1U | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__staleVector2));
    }
    if ((IData)(((0U == (0x18000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U])) 
                 & ((0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                              >> 7U)) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))))) {
        vlSelf->Top__DOT__decodeIssue__DOT__staleVector2 
            = (2U | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__staleVector2));
    }
    vlSelf->Top__DOT__lowerInFlightLoad1 = ((0U != 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                 >> 2U))) 
                                            && (1U 
                                                & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                    [
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                        >> 2U))] 
                                                    >> 6U) 
                                                   & (~ 
                                                      (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                           >> 2U))] 
                                                       >> 1U)))));
    vlSelf->Top__DOT__lowerInFlightLoad2 = ((0U != 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                 >> 7U))) 
                                            && (1U 
                                                & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                    [
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                        >> 7U))] 
                                                    >> 6U) 
                                                   & (~ 
                                                      (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                           >> 7U))] 
                                                       >> 1U)))));
    if ((0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1))) {
        vlSelf->Top__DOT__oldUpperStatus = ((1U & (IData)(vlSelf->Top__DOT__oldUpperStatus)) 
                                            | ((0x20U 
                                                & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                   [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1] 
                                                   << 4U)) 
                                               | (0x1eU 
                                                  & (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                     [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1] 
                                                     >> 1U))));
        vlSelf->Top__DOT__oldUpperStatus = ((0x3eU 
                                             & (IData)(vlSelf->Top__DOT__oldUpperStatus)) 
                                            | (1U & 
                                               vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                               [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1]));
    } else {
        vlSelf->Top__DOT__oldUpperStatus = (0x20U | (IData)(vlSelf->Top__DOT__oldUpperStatus));
        vlSelf->Top__DOT__oldUpperStatus = (1U | (IData)(vlSelf->Top__DOT__oldUpperStatus));
    }
    vlSelf->Top__DOT__destRegLoad1 = ((0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)) 
                                      && (1U & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                 [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1] 
                                                 >> 6U) 
                                                & (~ 
                                                   (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                    [vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1] 
                                                    >> 1U)))));
    vlSelf->Top__DOT__decodeIssue__DOT__staleVector1 = 0U;
    if (((0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                   >> 2U)) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1))) {
        vlSelf->Top__DOT__decodeIssue__DOT__staleVector1 
            = (1U | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__staleVector1));
    }
    if ((IData)(((0U == (0x18000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U])) 
                 & ((0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                              >> 7U)) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1))))) {
        vlSelf->Top__DOT__decodeIssue__DOT__staleVector1 
            = (2U | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__staleVector1));
    }
    vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable = 0U;
    vlSelf->Top__DOT__upperInFlightLoad2 = ((0U != 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                                                 >> 7U))) 
                                            && (1U 
                                                & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                    [
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                                                        >> 7U))] 
                                                    >> 6U) 
                                                   & (~ 
                                                      (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                                                           >> 7U))] 
                                                       >> 1U)))));
    vlSelf->Top__DOT__upperInFlightLoad1 = ((0U != 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                                                 >> 2U))) 
                                            && (1U 
                                                & ((vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                    [
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                                                        >> 2U))] 
                                                    >> 6U) 
                                                   & (~ 
                                                      (vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                                                           >> 2U))] 
                                                       >> 1U)))));
    vlSelf->Top__DOT__redirect1 = 0U;
    if ((1U & vlSelf->Top__DOT__exPayload1[0U])) {
        if ((0x1000U & vlSelf->Top__DOT__exPayload1[0U])) {
            if ((0x800U & vlSelf->Top__DOT__exPayload1[0U])) {
                if ((1U & (~ (vlSelf->Top__DOT__exPayload1[0U] 
                              >> 0xaU)))) {
                    vlSelf->Top__DOT__redirect1 = (Top__DOT__execute__DOT__upperOperand1 
                                                   >= Top__DOT__execute__DOT__upperOperand2);
                }
            } else {
                vlSelf->Top__DOT__redirect1 = ((0x400U 
                                                & vlSelf->Top__DOT__exPayload1[0U])
                                                ? (Top__DOT__execute__DOT__upperOperand1 
                                                   < Top__DOT__execute__DOT__upperOperand2)
                                                : VL_GTES_III(32, Top__DOT__execute__DOT__upperOperand1, Top__DOT__execute__DOT__upperOperand2));
            }
        } else if ((0x800U & vlSelf->Top__DOT__exPayload1[0U])) {
            vlSelf->Top__DOT__redirect1 = ((0x400U 
                                            & vlSelf->Top__DOT__exPayload1[0U])
                                            ? VL_LTS_III(32, Top__DOT__execute__DOT__upperOperand1, Top__DOT__execute__DOT__upperOperand2)
                                            : (Top__DOT__execute__DOT__upperOperand1 
                                               != Top__DOT__execute__DOT__upperOperand2));
        } else if ((0x400U & vlSelf->Top__DOT__exPayload1[0U])) {
            vlSelf->Top__DOT__redirect1 = (Top__DOT__execute__DOT__upperOperand1 
                                           == Top__DOT__execute__DOT__upperOperand2);
        }
        if ((0U != (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                          >> 0xdU)))) {
            if ((1U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                              >> 0xdU)))) {
                vlSelf->Top__DOT__redirect1 = 1U;
            } else if ((2U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                                     >> 0xdU)))) {
                vlSelf->Top__DOT__redirect1 = 1U;
            }
        }
    } else {
        vlSelf->Top__DOT__redirect1 = 0U;
    }
    vlSelf->Top__DOT__resultPayload1 = 0ULL;
    vlSelf->Top__DOT__resultPayload1 = ((0x3fffffffffULL 
                                         & vlSelf->Top__DOT__resultPayload1) 
                                        | ((QData)((IData)(
                                                           (0xfU 
                                                            & (vlSelf->Top__DOT__exPayload1[0U] 
                                                               >> 1U)))) 
                                           << 0x26U));
    if ((IData)(((1U == (0x301U & vlSelf->Top__DOT__exPayload1[0U])) 
                 & (~ (IData)(vlSelf->reset))))) {
        vlSelf->Top__DOT__resultPayload1 = ((0x3ffffffffc0ULL 
                                             & vlSelf->Top__DOT__resultPayload1) 
                                            | (IData)((IData)(
                                                              (1U 
                                                               | (0x3eU 
                                                                  & (vlSelf->Top__DOT__exPayload1[0U] 
                                                                     >> 0x12U))))));
        vlSelf->Top__DOT__resultPayload1 = ((0x3c00000003fULL 
                                             & vlSelf->Top__DOT__resultPayload1) 
                                            | ((QData)((IData)(
                                                               ((0U 
                                                                 != 
                                                                 (3U 
                                                                  & (vlSelf->Top__DOT__exPayload1[0U] 
                                                                     >> 0xdU)))
                                                                 ? 
                                                                ((vlSelf->Top__DOT__exPayload1[1U] 
                                                                  << 8U) 
                                                                 | (vlSelf->Top__DOT__exPayload1[0U] 
                                                                    >> 0x18U))
                                                                 : vlSelf->Top__DOT__execute__DOT__result1))) 
                                               << 6U));
    }
    vlSelf->Top__DOT__execute__DOT__illegal1 = 0U;
    Top__DOT__execute__DOT__redirectVector1 = ((vlSelf->Top__DOT__exPayload1[1U] 
                                                << 8U) 
                                               | (vlSelf->Top__DOT__exPayload1[0U] 
                                                  >> 0x18U));
    if (((IData)((0U != (0x7c00U & vlSelf->Top__DOT__exPayload1[0U]))) 
         & vlSelf->Top__DOT__exPayload1[0U])) {
        if ((2U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                          >> 0xdU)))) {
            Top__DOT__execute__DOT__redirectVector1 
                = (0xfffffffeU & vlSelf->Top__DOT__execute__DOT__result1);
        } else if ((1U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                                 >> 0xdU)))) {
            Top__DOT__execute__DOT__redirectVector1 
                = vlSelf->Top__DOT__execute__DOT__result1;
        }
        if ((0U != (3U & Top__DOT__execute__DOT__redirectVector1))) {
            vlSelf->Top__DOT__execute__DOT__illegal1 = 1U;
        }
    }
    Top__DOT__execute__DOT__lowerOperand1 = ((2U & 
                                              vlSelf->Top__DOT__exPayload2[0U])
                                              ? vlSelf->Top__DOT__execute__DOT__result1
                                              : ((vlSelf->Top__DOT__exPayload2[3U] 
                                                  << 0xbU) 
                                                 | (vlSelf->Top__DOT__exPayload2[2U] 
                                                    >> 0x15U)));
    Top__DOT__execute__DOT__lowerOperand2 = ((4U & 
                                              vlSelf->Top__DOT__exPayload2[0U])
                                              ? vlSelf->Top__DOT__execute__DOT__result1
                                              : ((vlSelf->Top__DOT__exPayload2[2U] 
                                                  << 0xbU) 
                                                 | (vlSelf->Top__DOT__exPayload2[1U] 
                                                    >> 0x15U)));
    vlSelf->Top__DOT__placeholderDMEM__DOT__validRequest 
        = (IData)(((3U == (3U & vlSelf->Top__DOT__memBusOut[0U])) 
                   & (~ vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister)));
    vlSelf->Top__DOT__lowerROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status) 
                                                  >> 1U))][1U] 
                                        << 0x15U) | 
                                       (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status) 
                                                  >> 1U))][0U] 
                                        >> 0xbU));
    vlSelf->Top__DOT__upperROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status) 
                                                  >> 1U))][1U] 
                                        << 0x15U) | 
                                       (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status) 
                                                  >> 1U))][0U] 
                                        >> 0xbU));
    vlSelf->Top__DOT__upperROBData1 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status) 
                                                  >> 1U))][1U] 
                                        << 0x15U) | 
                                       (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status) 
                                                  >> 1U))][0U] 
                                        >> 0xbU));
    vlSelf->Top__DOT__lowerROBData2 = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status) 
                                                  >> 1U))][1U] 
                                        << 0x15U) | 
                                       (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                        [(0xfU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status) 
                                                  >> 1U))][0U] 
                                        >> 0xbU));
    vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer 
        = (0x1fU & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer) 
                    + (IData)(Top__DOT__reorderBuffer__DOT__retireCount)));
    if ((1U & (vlSelf->Top__DOT__exPayload1[0U] & (~ (IData)(vlSelf->Top__DOT__execute__DOT__illegal1))))) {
        if ((0U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                          >> 8U)))) {
            vlSelf->Top__DOT__memPayload[0U] = 0U;
            vlSelf->Top__DOT__memPayload[1U] = 0U;
            vlSelf->Top__DOT__memPayload[2U] = 0U;
        } else if (((1U == (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                                  >> 8U))) || (2U == 
                                               (3U 
                                                & (vlSelf->Top__DOT__exPayload1[0U] 
                                                   >> 8U))))) {
            vlSelf->Top__DOT__memPayload[0U] = ((0xfffU 
                                                 & vlSelf->Top__DOT__memPayload[0U]) 
                                                | (((IData)(
                                                            (((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result1)) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               ((vlSelf->Top__DOT__exPayload1[1U] 
                                                                                << 8U) 
                                                                                | (vlSelf->Top__DOT__exPayload1[0U] 
                                                                                >> 0x18U)))))) 
                                                    << 0xeU) 
                                                   | (0x3000U 
                                                      & (vlSelf->Top__DOT__exPayload1[0U] 
                                                         << 4U))));
            vlSelf->Top__DOT__memPayload[1U] = ((0xfffU 
                                                 & ((IData)(
                                                            (((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result1)) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               ((vlSelf->Top__DOT__exPayload1[1U] 
                                                                                << 8U) 
                                                                                | (vlSelf->Top__DOT__exPayload1[0U] 
                                                                                >> 0x18U)))))) 
                                                    >> 0x12U)) 
                                                | ((0x3000U 
                                                    & ((IData)(
                                                               (((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result1)) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                ((vlSelf->Top__DOT__exPayload1[1U] 
                                                                                << 8U) 
                                                                                | (vlSelf->Top__DOT__exPayload1[0U] 
                                                                                >> 0x18U)))))) 
                                                       >> 0x12U)) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result1)) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                ((vlSelf->Top__DOT__exPayload1[1U] 
                                                                                << 8U) 
                                                                                | (vlSelf->Top__DOT__exPayload1[0U] 
                                                                                >> 0x18U))))) 
                                                               >> 0x20U)) 
                                                      << 0xeU)));
            vlSelf->Top__DOT__memPayload[2U] = (0x3fffU 
                                                & ((0xfffU 
                                                    & ((IData)(
                                                               ((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result1)) 
                                                                  << 0x20U) 
                                                                 | (QData)((IData)(
                                                                                ((vlSelf->Top__DOT__exPayload1[1U] 
                                                                                << 8U) 
                                                                                | (vlSelf->Top__DOT__exPayload1[0U] 
                                                                                >> 0x18U))))) 
                                                                >> 0x20U)) 
                                                       >> 0x12U)) 
                                                   | (0x3000U 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(vlSelf->Top__DOT__execute__DOT__result1)) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(
                                                                                ((vlSelf->Top__DOT__exPayload1[1U] 
                                                                                << 8U) 
                                                                                | (vlSelf->Top__DOT__exPayload1[0U] 
                                                                                >> 0x18U))))) 
                                                                  >> 0x20U)) 
                                                         >> 0x12U))));
            vlSelf->Top__DOT__memPayload[0U] = ((0xfffff000U 
                                                 & vlSelf->Top__DOT__memPayload[0U]) 
                                                | ((0xe00U 
                                                    & (vlSelf->Top__DOT__exPayload1[0U] 
                                                       << 4U)) 
                                                   | ((0x1f0U 
                                                       & (vlSelf->Top__DOT__exPayload1[0U] 
                                                          >> 0xfU)) 
                                                      | (0xfU 
                                                         & (vlSelf->Top__DOT__exPayload1[0U] 
                                                            >> 1U)))));
        }
    } else {
        vlSelf->Top__DOT__memPayload[0U] = 0U;
        vlSelf->Top__DOT__memPayload[1U] = 0U;
        vlSelf->Top__DOT__memPayload[2U] = 0U;
    }
    vlSelf->Top__DOT__memFreeSlot = 0U;
    Top__DOT__memoryQueue__DOT__unnamedblk1__DOT__memFreeSlotsTemp 
        = (0xfU & (((((IData)(8U) - (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)) 
                     + (1U & (IData)(vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister))) 
                    - ((0U != (3U & (vlSelf->Top__DOT__payload1[0U] 
                                     >> 0x19U))) & 
                       vlSelf->Top__DOT__payload1[0U])) 
                   - ((0U != (3U & (vlSelf->Top__DOT__exPayload1[0U] 
                                    >> 8U))) & ((~ (IData)(vlSelf->Top__DOT__execute__DOT__illegal1)) 
                                                & vlSelf->Top__DOT__exPayload1[0U]))));
    if ((0U < (IData)(Top__DOT__memoryQueue__DOT__unnamedblk1__DOT__memFreeSlotsTemp))) {
        vlSelf->Top__DOT__memFreeSlot = 1U;
    }
    Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0 
        = ((~ (IData)(vlSelf->Top__DOT__execute__DOT__illegal1)) 
           & (IData)(vlSelf->Top__DOT__redirect1));
    Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0 
        = VL_LTS_III(32, Top__DOT__execute__DOT__lowerOperand1, Top__DOT__execute__DOT__lowerOperand2);
    Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0 
        = (Top__DOT__execute__DOT__lowerOperand1 < Top__DOT__execute__DOT__lowerOperand2);
    Top__DOT__redirect2 = 0U;
    if ((1U & vlSelf->Top__DOT__exPayload2[0U])) {
        if ((0x200U & vlSelf->Top__DOT__exPayload2[0U])) {
            if ((0x100U & vlSelf->Top__DOT__exPayload2[0U])) {
                if ((1U & (~ (vlSelf->Top__DOT__exPayload2[0U] 
                              >> 7U)))) {
                    Top__DOT__redirect2 = (Top__DOT__execute__DOT__lowerOperand1 
                                           >= Top__DOT__execute__DOT__lowerOperand2);
                }
            } else {
                Top__DOT__redirect2 = ((0x80U & vlSelf->Top__DOT__exPayload2[0U])
                                        ? (IData)(Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0)
                                        : VL_GTES_III(32, Top__DOT__execute__DOT__lowerOperand1, Top__DOT__execute__DOT__lowerOperand2));
            }
        } else if ((0x100U & vlSelf->Top__DOT__exPayload2[0U])) {
            Top__DOT__redirect2 = ((0x80U & vlSelf->Top__DOT__exPayload2[0U])
                                    ? (IData)(Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0)
                                    : (Top__DOT__execute__DOT__lowerOperand1 
                                       != Top__DOT__execute__DOT__lowerOperand2));
        } else if ((0x80U & vlSelf->Top__DOT__exPayload2[0U])) {
            Top__DOT__redirect2 = (Top__DOT__execute__DOT__lowerOperand1 
                                   == Top__DOT__execute__DOT__lowerOperand2);
        }
        if ((0U != (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                          >> 0xaU)))) {
            if ((1U == (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                              >> 0xaU)))) {
                Top__DOT__redirect2 = 1U;
            } else if ((2U == (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                                     >> 0xaU)))) {
                Top__DOT__redirect2 = 1U;
            }
        }
    } else {
        Top__DOT__redirect2 = 0U;
    }
    vlSelf->Top__DOT__execute__DOT__result2 = 0U;
    if ((0x8000U & vlSelf->Top__DOT__exPayload2[0U])) {
        if ((1U & (~ (vlSelf->Top__DOT__exPayload2[0U] 
                      >> 0xeU)))) {
            if ((1U & (~ (vlSelf->Top__DOT__exPayload2[0U] 
                          >> 0xdU)))) {
                vlSelf->Top__DOT__execute__DOT__result2 
                    = ((0x1000U & vlSelf->Top__DOT__exPayload2[0U])
                        ? ((IData)(Top__DOT__execute__DOT____VdfgExtracted_h4cbec2d7__0)
                            ? 1U : 0U) : ((IData)(Top__DOT__execute__DOT____VdfgExtracted_h4da36787__0)
                                           ? 1U : 0U));
            }
        }
    } else {
        vlSelf->Top__DOT__execute__DOT__result2 = (
                                                   (0x4000U 
                                                    & vlSelf->Top__DOT__exPayload2[0U])
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->Top__DOT__exPayload2[0U])
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->Top__DOT__exPayload2[0U])
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, Top__DOT__execute__DOT__lowerOperand1, 
                                                                    (0x1fU 
                                                                     & Top__DOT__execute__DOT__lowerOperand2))
                                                      : 
                                                     (Top__DOT__execute__DOT__lowerOperand1 
                                                      >> 
                                                      (0x1fU 
                                                       & Top__DOT__execute__DOT__lowerOperand2)))
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->Top__DOT__exPayload2[0U])
                                                      ? 
                                                     (Top__DOT__execute__DOT__lowerOperand1 
                                                      << 
                                                      (0x1fU 
                                                       & Top__DOT__execute__DOT__lowerOperand2))
                                                      : 
                                                     (Top__DOT__execute__DOT__lowerOperand1 
                                                      ^ Top__DOT__execute__DOT__lowerOperand2)))
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->Top__DOT__exPayload2[0U])
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->Top__DOT__exPayload2[0U])
                                                      ? 
                                                     (Top__DOT__execute__DOT__lowerOperand1 
                                                      | Top__DOT__execute__DOT__lowerOperand2)
                                                      : 
                                                     (Top__DOT__execute__DOT__lowerOperand1 
                                                      & Top__DOT__execute__DOT__lowerOperand2))
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->Top__DOT__exPayload2[0U])
                                                      ? 
                                                     (Top__DOT__execute__DOT__lowerOperand1 
                                                      - Top__DOT__execute__DOT__lowerOperand2)
                                                      : 
                                                     (Top__DOT__execute__DOT__lowerOperand1 
                                                      + Top__DOT__execute__DOT__lowerOperand2))));
    }
    Top__DOT__execute__DOT__illegal2 = 0U;
    Top__DOT__execute__DOT__redirectVector2 = ((vlSelf->Top__DOT__exPayload2[1U] 
                                                << 0xbU) 
                                               | (vlSelf->Top__DOT__exPayload2[0U] 
                                                  >> 0x15U));
    if (((IData)((0U != (0xf80U & vlSelf->Top__DOT__exPayload2[0U]))) 
         & vlSelf->Top__DOT__exPayload2[0U])) {
        if ((2U == (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                          >> 0xaU)))) {
            Top__DOT__execute__DOT__redirectVector2 
                = (0xfffffffeU & vlSelf->Top__DOT__execute__DOT__result2);
        } else if ((1U == (3U & (vlSelf->Top__DOT__exPayload2[0U] 
                                 >> 0xaU)))) {
            Top__DOT__execute__DOT__redirectVector2 
                = vlSelf->Top__DOT__execute__DOT__result2;
        }
        if ((0U != (3U & Top__DOT__execute__DOT__redirectVector2))) {
            Top__DOT__execute__DOT__illegal2 = 1U;
        }
    }
    vlSelf->Top__DOT__resultPayload2 = 0ULL;
    vlSelf->Top__DOT__resultPayload2 = ((0x3fffffffffULL 
                                         & vlSelf->Top__DOT__resultPayload2) 
                                        | ((QData)((IData)(
                                                           (0xfU 
                                                            & (vlSelf->Top__DOT__exPayload2[0U] 
                                                               >> 3U)))) 
                                           << 0x26U));
    if ((1U & ((vlSelf->Top__DOT__exPayload2[0U] & 
                (~ ((IData)(vlSelf->Top__DOT__redirect1) 
                    & (~ (IData)(vlSelf->Top__DOT__execute__DOT__illegal1))))) 
               & (~ (IData)(vlSelf->reset))))) {
        vlSelf->Top__DOT__resultPayload2 = ((0x3ffffffffc0ULL 
                                             & vlSelf->Top__DOT__resultPayload2) 
                                            | (IData)((IData)(
                                                              (1U 
                                                               | (0x3eU 
                                                                  & (vlSelf->Top__DOT__exPayload2[0U] 
                                                                     >> 0xfU))))));
        vlSelf->Top__DOT__resultPayload2 = ((0x3c00000003fULL 
                                             & vlSelf->Top__DOT__resultPayload2) 
                                            | ((QData)((IData)(
                                                               ((0U 
                                                                 != 
                                                                 (3U 
                                                                  & (vlSelf->Top__DOT__exPayload2[0U] 
                                                                     >> 0xaU)))
                                                                 ? 
                                                                ((vlSelf->Top__DOT__exPayload2[1U] 
                                                                  << 0xbU) 
                                                                 | (vlSelf->Top__DOT__exPayload2[0U] 
                                                                    >> 0x15U))
                                                                 : vlSelf->Top__DOT__execute__DOT__result2))) 
                                               << 6U));
    }
    Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0 
        = ((~ (IData)(Top__DOT__execute__DOT__illegal2)) 
           & (IData)(Top__DOT__redirect2));
    Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0 
        = (0xfU & ((IData)(vlSelf->Top__DOT__redirect1)
                    ? (IData)((vlSelf->Top__DOT__resultPayload1 
                               >> 0x26U)) : (IData)(
                                                    (vlSelf->Top__DOT__resultPayload2 
                                                     >> 0x26U))));
    vlSelf->Top__DOT__redirectVector = ((IData)(Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0)
                                         ? Top__DOT__execute__DOT__redirectVector1
                                         : ((IData)(Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0)
                                             ? Top__DOT__execute__DOT__redirectVector2
                                             : 0U));
    vlSelf->Top__DOT__redirect = ((IData)(Top__DOT__execute__DOT____VdfgTmp_hb1671e1e__0) 
                                  | ((~ (IData)(vlSelf->Top__DOT__execute__DOT__illegal1)) 
                                     & (IData)(Top__DOT__execute__DOT____VdfgTmp_h86f5dc7e__0)));
    Top__DOT__reorderBuffer__DOT__flushDest3 = (0x1fU 
                                                & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                   [
                                                   (0xfU 
                                                    & ((IData)(3U) 
                                                       + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)))][0U] 
                                                   >> 6U));
    Top__DOT__reorderBuffer__DOT__flushDest2 = (0x1fU 
                                                & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                   [
                                                   (0xfU 
                                                    & ((IData)(2U) 
                                                       + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)))][0U] 
                                                   >> 6U));
    Top__DOT__reorderBuffer__DOT__flushDest1 = (0x1fU 
                                                & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                   [
                                                   (0xfU 
                                                    & ((IData)(1U) 
                                                       + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)))][0U] 
                                                   >> 6U));
    Top__DOT__reorderBuffer__DOT__redirectPointer = 
        ((0x10U & ((((1U & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer) 
                            >> 4U)) != (1U & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer) 
                                              >> 4U)))
                     ? (((0xfU & ((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0))) 
                         <= (0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer)))
                         ? ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer) 
                            >> 4U) : ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer) 
                                      >> 4U)) : ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer) 
                                                 >> 4U)) 
                   << 4U)) | (0xfU & ((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0))));
    if (vlSelf->reset) {
        vlSelf->Top__DOT__instructionMemory__DOT__redirectAddress = 0U;
        vlSelf->Top__DOT__instructionMemory__DOT__nextAddress = 0x10U;
    } else {
        vlSelf->Top__DOT__instructionMemory__DOT__redirectAddress 
            = vlSelf->Top__DOT__redirectVector;
        vlSelf->Top__DOT__instructionMemory__DOT__nextAddress 
            = ((IData)(0x10U) + vlSelf->Top__DOT__redirectVector);
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[2U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[3U] = 0U;
    Top__DOT__operandSelect__DOT__upperOperand1 = 0U;
    Top__DOT__operandSelect__DOT__upperOperand2 = 0U;
    if ((0U == (0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                         >> 2U)))) {
        Top__DOT__operandSelect__DOT__upperOperand1 = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = vlSelf->Top__DOT__upperSourceData1;
    } else if ((0x20U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = vlSelf->Top__DOT__upperROBData1;
    } else if ((((0xfU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                  >> 0x26U))) == (0xfU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status) 
                                                     >> 1U))) 
                & vlSelf->Top__DOT__exPayload2[0U])) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0xfU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                 >> 0x26U))) == (0xfU 
                                                 & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status) 
                                                    >> 1U)))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    if ((0U == (0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                         >> 7U)))) {
        Top__DOT__operandSelect__DOT__upperOperand2 = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = vlSelf->Top__DOT__upperSourceData2;
    } else if ((0x20U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = vlSelf->Top__DOT__upperROBData2;
    } else if ((((0xfU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                  >> 0x26U))) == (0xfU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status) 
                                                     >> 1U))) 
                & vlSelf->Top__DOT__exPayload2[0U])) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0xfU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                 >> 0x26U))) == (0xfU 
                                                 & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status) 
                                                    >> 1U)))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
        = ((0xffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
           | ((IData)(((0x10000000U & vlSelf->Top__DOT__payload1[0U])
                        ? ((0x8000000U & vlSelf->Top__DOT__payload1[0U])
                            ? (QData)((IData)(((vlSelf->Top__DOT__payload1[2U] 
                                                << 0x1eU) 
                                               | (vlSelf->Top__DOT__payload1[1U] 
                                                  >> 2U))))
                            : (((QData)((IData)(((vlSelf->Top__DOT__payload1[3U] 
                                                  << 0x14U) 
                                                 | (vlSelf->Top__DOT__payload1[2U] 
                                                    >> 0xcU)))) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload1[2U] 
                                                              << 0x1eU) 
                                                             | (vlSelf->Top__DOT__payload1[1U] 
                                                                >> 2U))))))
                        : ((0x8000000U & vlSelf->Top__DOT__payload1[0U])
                            ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload1[2U] 
                                                              << 0x1eU) 
                                                             | (vlSelf->Top__DOT__payload1[1U] 
                                                                >> 2U)))))
                            : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2)))))) 
              << 0x18U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[2U] 
        = (((IData)(((0x10000000U & vlSelf->Top__DOT__payload1[0U])
                      ? ((0x8000000U & vlSelf->Top__DOT__payload1[0U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload1[2U] 
                                              << 0x1eU) 
                                             | (vlSelf->Top__DOT__payload1[1U] 
                                                >> 2U))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload1[3U] 
                                                << 0x14U) 
                                               | (vlSelf->Top__DOT__payload1[2U] 
                                                  >> 0xcU)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x1eU) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 2U))))))
                      : ((0x8000000U & vlSelf->Top__DOT__payload1[0U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x1eU) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 2U)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2)))))) 
            >> 8U) | ((IData)((((0x10000000U & vlSelf->Top__DOT__payload1[0U])
                                 ? ((0x8000000U & vlSelf->Top__DOT__payload1[0U])
                                     ? (QData)((IData)(
                                                       ((vlSelf->Top__DOT__payload1[2U] 
                                                         << 0x1eU) 
                                                        | (vlSelf->Top__DOT__payload1[1U] 
                                                           >> 2U))))
                                     : (((QData)((IData)(
                                                         ((vlSelf->Top__DOT__payload1[3U] 
                                                           << 0x14U) 
                                                          | (vlSelf->Top__DOT__payload1[2U] 
                                                             >> 0xcU)))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x1eU) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 2U))))))
                                 : ((0x8000000U & vlSelf->Top__DOT__payload1[0U])
                                     ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x1eU) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 2U)))))
                                     : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                         << 0x20U) 
                                        | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2))))) 
                               >> 0x20U)) << 0x18U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[3U] 
        = ((IData)((((0x10000000U & vlSelf->Top__DOT__payload1[0U])
                      ? ((0x8000000U & vlSelf->Top__DOT__payload1[0U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload1[2U] 
                                              << 0x1eU) 
                                             | (vlSelf->Top__DOT__payload1[1U] 
                                                >> 2U))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload1[3U] 
                                                << 0x14U) 
                                               | (vlSelf->Top__DOT__payload1[2U] 
                                                  >> 0xcU)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x1eU) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 2U))))))
                      : ((0x8000000U & vlSelf->Top__DOT__payload1[0U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x1eU) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 2U)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2))))) 
                    >> 0x20U)) >> 8U);
    if ((0U != (3U & (vlSelf->Top__DOT__payload1[0U] 
                      >> 0xdU)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
            = ((0xffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload1[3U] 
                                   << 0x14U) | (vlSelf->Top__DOT__payload1[2U] 
                                                >> 0xcU))) 
                  << 0x18U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
            = ((0xff000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload1[3U] 
                                   << 0x14U) | (vlSelf->Top__DOT__payload1[2U] 
                                                >> 0xcU))) 
                  >> 8U));
    } else if ((0U != (7U & (vlSelf->Top__DOT__payload1[0U] 
                             >> 0x13U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
            = ((0xffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
               | ((((vlSelf->Top__DOT__payload1[3U] 
                     << 0x14U) | (vlSelf->Top__DOT__payload1[2U] 
                                  >> 0xcU)) + ((vlSelf->Top__DOT__payload1[2U] 
                                                << 0x1eU) 
                                               | (vlSelf->Top__DOT__payload1[1U] 
                                                  >> 2U))) 
                  << 0x18U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
            = ((0xff000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
               | ((((vlSelf->Top__DOT__payload1[3U] 
                     << 0x14U) | (vlSelf->Top__DOT__payload1[2U] 
                                  >> 0xcU)) + ((vlSelf->Top__DOT__payload1[2U] 
                                                << 0x1eU) 
                                               | (vlSelf->Top__DOT__payload1[1U] 
                                                  >> 2U))) 
                  >> 8U));
    } else if ((2U == (3U & (vlSelf->Top__DOT__payload1[0U] 
                             >> 0x19U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
            = ((0xffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
               | (Top__DOT__operandSelect__DOT__upperOperand2 
                  << 0x18U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
            = ((0xff000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
               | (Top__DOT__operandSelect__DOT__upperOperand2 
                  >> 8U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
        = ((0xff0003ffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
           | (0xfffffc00U & ((0xf80000U & ((vlSelf->Top__DOT__payload1[1U] 
                                            << 0x16U) 
                                           | (0x380000U 
                                              & (vlSelf->Top__DOT__payload1[0U] 
                                                 >> 0xaU)))) 
                             | ((0x7e000U & vlSelf->Top__DOT__payload1[0U]) 
                                | (0x1c00U & (vlSelf->Top__DOT__payload1[0U] 
                                              >> 9U))))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
        = ((0xfffffc01U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
           | (0xfffffffeU & ((0x3e0U & (vlSelf->Top__DOT__payload1[0U] 
                                        >> 0x11U)) 
                             | (0x1eU & (vlSelf->Top__DOT__payload1[0U] 
                                         >> 8U)))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
        = ((0xfffffffeU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
           | ((1U & ((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->Top__DOT__redirect)))) 
              && (1U & vlSelf->Top__DOT__payload1[0U])));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[2U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[3U] = 0U;
    Top__DOT__operandSelect__DOT__lowerOperand1 = 0U;
    Top__DOT__operandSelect__DOT__lowerOperand2 = 0U;
    if ((0U == (0x1fU & ((vlSelf->Top__DOT__payload2[2U] 
                          << 1U) | (vlSelf->Top__DOT__payload2[1U] 
                                    >> 0x1fU))))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = vlSelf->Top__DOT__lowerSourceData1;
    } else if ((0x20U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = vlSelf->Top__DOT__lowerROBData1;
    } else if ((((0xfU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                  >> 0x26U))) == (0xfU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status) 
                                                     >> 1U))) 
                & vlSelf->Top__DOT__exPayload2[0U])) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0xfU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                 >> 0x26U))) == (0xfU 
                                                 & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status) 
                                                    >> 1U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    if ((0U == (0x1fU & (vlSelf->Top__DOT__payload2[2U] 
                         >> 4U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 = 0U;
    } else if ((1U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = vlSelf->Top__DOT__lowerSourceData2;
    } else if ((0x20U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = vlSelf->Top__DOT__lowerROBData2;
    } else if ((((0xfU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                  >> 0x26U))) == (0xfU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status) 
                                                     >> 1U))) 
                & vlSelf->Top__DOT__exPayload2[0U])) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0xfU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                 >> 0x26U))) == (0xfU 
                                                 & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status) 
                                                    >> 1U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] 
        = ((0x1fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U]) 
           | ((IData)(((0x2000000U & vlSelf->Top__DOT__payload2[0U])
                        ? ((0x1000000U & vlSelf->Top__DOT__payload2[0U])
                            ? (QData)((IData)(((vlSelf->Top__DOT__payload2[1U] 
                                                << 1U) 
                                               | (vlSelf->Top__DOT__payload2[0U] 
                                                  >> 0x1fU))))
                            : (((QData)((IData)(((vlSelf->Top__DOT__payload2[3U] 
                                                  << 0x17U) 
                                                 | (vlSelf->Top__DOT__payload2[2U] 
                                                    >> 9U)))) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[1U] 
                                                              << 1U) 
                                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                                >> 0x1fU))))))
                        : ((0x1000000U & vlSelf->Top__DOT__payload2[0U])
                            ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[1U] 
                                                              << 1U) 
                                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                                >> 0x1fU)))))
                            : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2)))))) 
              << 0x15U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[2U] 
        = (((IData)(((0x2000000U & vlSelf->Top__DOT__payload2[0U])
                      ? ((0x1000000U & vlSelf->Top__DOT__payload2[0U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload2[1U] 
                                              << 1U) 
                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                >> 0x1fU))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload2[3U] 
                                                << 0x17U) 
                                               | (vlSelf->Top__DOT__payload2[2U] 
                                                  >> 9U)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[1U] 
                                                            << 1U) 
                                                           | (vlSelf->Top__DOT__payload2[0U] 
                                                              >> 0x1fU))))))
                      : ((0x1000000U & vlSelf->Top__DOT__payload2[0U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[1U] 
                                                            << 1U) 
                                                           | (vlSelf->Top__DOT__payload2[0U] 
                                                              >> 0x1fU)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2)))))) 
            >> 0xbU) | ((IData)((((0x2000000U & vlSelf->Top__DOT__payload2[0U])
                                   ? ((0x1000000U & 
                                       vlSelf->Top__DOT__payload2[0U])
                                       ? (QData)((IData)(
                                                         ((vlSelf->Top__DOT__payload2[1U] 
                                                           << 1U) 
                                                          | (vlSelf->Top__DOT__payload2[0U] 
                                                             >> 0x1fU))))
                                       : (((QData)((IData)(
                                                           ((vlSelf->Top__DOT__payload2[3U] 
                                                             << 0x17U) 
                                                            | (vlSelf->Top__DOT__payload2[2U] 
                                                               >> 9U)))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[1U] 
                                                              << 1U) 
                                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                                >> 0x1fU))))))
                                   : ((0x1000000U & 
                                       vlSelf->Top__DOT__payload2[0U])
                                       ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[1U] 
                                                              << 1U) 
                                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                                >> 0x1fU)))))
                                       : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                           << 0x20U) 
                                          | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2))))) 
                                 >> 0x20U)) << 0x15U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[3U] 
        = ((IData)((((0x2000000U & vlSelf->Top__DOT__payload2[0U])
                      ? ((0x1000000U & vlSelf->Top__DOT__payload2[0U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload2[1U] 
                                              << 1U) 
                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                >> 0x1fU))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload2[3U] 
                                                << 0x17U) 
                                               | (vlSelf->Top__DOT__payload2[2U] 
                                                  >> 9U)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[1U] 
                                                            << 1U) 
                                                           | (vlSelf->Top__DOT__payload2[0U] 
                                                              >> 0x1fU))))))
                      : ((0x1000000U & vlSelf->Top__DOT__payload2[0U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[1U] 
                                                            << 1U) 
                                                           | (vlSelf->Top__DOT__payload2[0U] 
                                                              >> 0x1fU)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2))))) 
                    >> 0x20U)) >> 0xbU);
    if ((0U != (3U & (vlSelf->Top__DOT__payload2[0U] 
                      >> 0xfU)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
            = ((0x1fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload2[3U] 
                                   << 0x17U) | (vlSelf->Top__DOT__payload2[2U] 
                                                >> 9U))) 
                  << 0x15U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] 
            = ((0xffe00000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload2[3U] 
                                   << 0x17U) | (vlSelf->Top__DOT__payload2[2U] 
                                                >> 9U))) 
                  >> 0xbU));
    } else if ((0U != (7U & (vlSelf->Top__DOT__payload2[0U] 
                             >> 0x15U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
            = ((0x1fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
               | ((((vlSelf->Top__DOT__payload2[3U] 
                     << 0x17U) | (vlSelf->Top__DOT__payload2[2U] 
                                  >> 9U)) + ((vlSelf->Top__DOT__payload2[1U] 
                                              << 1U) 
                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                >> 0x1fU))) 
                  << 0x15U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] 
            = ((0xffe00000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U]) 
               | ((((vlSelf->Top__DOT__payload2[3U] 
                     << 0x17U) | (vlSelf->Top__DOT__payload2[2U] 
                                  >> 9U)) + ((vlSelf->Top__DOT__payload2[1U] 
                                              << 1U) 
                                             | (vlSelf->Top__DOT__payload2[0U] 
                                                >> 0x1fU))) 
                  >> 0xbU));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xffe0007fU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (0xffffff80U & ((0x1f0000U & (vlSelf->Top__DOT__payload2[0U] 
                                           >> 0xaU)) 
                             | ((0xfc00U & (vlSelf->Top__DOT__payload2[0U] 
                                            >> 5U)) 
                                | (0x380U & (vlSelf->Top__DOT__payload2[0U] 
                                             >> 0xeU))))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xffffff87U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (0x78U & (vlSelf->Top__DOT__payload2[0U] 
                       >> 8U)));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xfffffffeU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | ((1U & ((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->Top__DOT__redirect)))) 
              && (1U & vlSelf->Top__DOT__payload2[0U])));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xfffffff9U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (6U & (vlSelf->Top__DOT__payload2[0U] 
                    >> 8U)));
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[0U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0;
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[1U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(0xfU) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[2U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(0xeU) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[3U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(0xdU) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[4U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(0xcU) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[5U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(0xbU) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[6U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(0xaU) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[7U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(9U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[8U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(8U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[9U] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(7U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[0xaU] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(6U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[0xbU] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(5U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[0xcU] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(4U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[0xdU] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(3U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[0xeU] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance 
        = (0xfU & ((IData)(2U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
    vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[0xfU] 
        = Top__DOT__reorderBuffer__DOT__unnamedblk2__DOT__unnamedblk3__DOT__distance;
    Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd 
        = Top__DOT__reorderBuffer__DOT__flushDest1;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & (- (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(1U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [1U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[1U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(2U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [2U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[2U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(3U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [3U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[3U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(4U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [4U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[4U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(5U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [5U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[5U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(6U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [6U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[6U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(7U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [7U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[7U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(8U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [8U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[8U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(9U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [9U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[9U][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xaU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xaU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xaU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xbU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xbU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xbU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xcU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xcU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xcU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xdU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xdU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xdU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xeU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xeU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xeU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xfU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xfU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xfU][0U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd 
        = Top__DOT__reorderBuffer__DOT__flushDest2;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & (- (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(1U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [1U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[1U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(2U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [2U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[2U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(3U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [3U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[3U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(4U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [4U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[4U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(5U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [5U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[5U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(6U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [6U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[6U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(7U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [7U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[7U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(8U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [8U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[8U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(9U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [9U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[9U][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xaU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xaU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xaU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xbU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xbU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xbU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xcU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xcU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xcU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xdU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xdU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xdU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xeU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xeU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xeU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xfU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xfU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xfU][1U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd 
        = Top__DOT__reorderBuffer__DOT__flushDest3;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & (- (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(1U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [1U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[1U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(2U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [2U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[2U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(3U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [3U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[3U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(4U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [4U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[4U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(5U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [5U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[5U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(6U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [6U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[6U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(7U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [7U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[7U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(8U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [8U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[8U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(9U) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [9U][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[9U][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xaU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xaU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xaU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xbU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xbU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xbU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xcU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xcU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xcU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xdU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xdU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xdU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xeU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xeU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xeU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0 
        = (((0xfU & ((IData)(0xfU) - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer))) 
            < (0xfU & (((IData)(1U) + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)) 
                       - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)))) 
           & ((0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                        [0xfU][0U] >> 6U)) == (IData)(Top__DOT__reorderBuffer__DOT__unnamedblk4__DOT__unnamedblk5__DOT__rd)));
    vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[0xfU][2U] 
        = Top__DOT__reorderBuffer__DOT____Vlvbound_hb7a6a0a1__0;
    Top__DOT__reorderBuffer__DOT__minIndex1 = 0U;
    Top__DOT__reorderBuffer__DOT__minValue1 = 0U;
    Top__DOT__reorderBuffer__DOT__found1 = 0U;
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 0U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [1U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [1U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [1U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 1U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [2U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [2U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [2U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 2U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [3U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [3U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [3U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 3U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [4U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [4U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [4U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 4U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [5U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [5U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [5U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 5U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [6U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [6U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [6U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 6U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [7U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [7U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [7U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 7U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [8U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [8U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [8U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 8U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [9U][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [9U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [9U];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 9U;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xaU][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xaU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xaU];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 0xaU;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xbU][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xbU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xbU];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 0xbU;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xcU][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xcU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xcU];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 0xcU;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xdU][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xdU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xdU];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 0xdU;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xeU][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xeU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xeU];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 0xeU;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xfU][0U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found1)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xfU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue1))))) {
            Top__DOT__reorderBuffer__DOT__minValue1 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xfU];
            Top__DOT__reorderBuffer__DOT__minIndex1 = 0xfU;
            Top__DOT__reorderBuffer__DOT__found1 = 1U;
        }
    }
    Top__DOT__reorderBuffer__DOT__minIndex2 = 0U;
    Top__DOT__reorderBuffer__DOT__minValue2 = 0U;
    Top__DOT__reorderBuffer__DOT__found2 = 0U;
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 0U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [1U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [1U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [1U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 1U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [2U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [2U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [2U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 2U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [3U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [3U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [3U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 3U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [4U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [4U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [4U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 4U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [5U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [5U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [5U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 5U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [6U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [6U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [6U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 6U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [7U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [7U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [7U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 7U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [8U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [8U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [8U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 8U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [9U][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [9U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [9U];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 9U;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xaU][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xaU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xaU];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 0xaU;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xbU][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xbU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xbU];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 0xbU;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xcU][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xcU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xcU];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 0xcU;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xdU][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xdU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xdU];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 0xdU;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xeU][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xeU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xeU];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 0xeU;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xfU][1U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xfU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue2))))) {
            Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xfU];
            Top__DOT__reorderBuffer__DOT__minIndex2 = 0xfU;
            Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    Top__DOT__reorderBuffer__DOT__minIndex3 = 0U;
    Top__DOT__reorderBuffer__DOT__minValue3 = 0U;
    Top__DOT__reorderBuffer__DOT__found3 = 0U;
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [1U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [1U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [1U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 1U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [2U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [2U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [2U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 2U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [3U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [3U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [3U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 3U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [4U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [4U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [4U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 4U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [5U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [5U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [5U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 5U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [6U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [6U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [6U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 6U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [7U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [7U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [7U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 7U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [8U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [8U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [8U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 8U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [9U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [9U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [9U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 9U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xaU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xaU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xaU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0xaU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xbU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xbU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xbU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0xbU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xcU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xcU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xcU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0xcU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xdU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xdU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xdU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0xdU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xeU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xeU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xeU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0xeU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xfU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xfU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xfU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0xfU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    Top__DOT__reorderBuffer__DOT__flushCount = (3U 
                                                & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer) 
                                                   - (IData)(Top__DOT__reorderBuffer__DOT__redirectPointer)));
    Top__DOT__reorderBuffer__DOT__usedEntries = (0x1fU 
                                                 & (((IData)(vlSelf->Top__DOT__redirect)
                                                      ? (IData)(Top__DOT__reorderBuffer__DOT__redirectPointer)
                                                      : (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer)) 
                                                    - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)));
    vlSelf->Top__DOT__reorderBuffer__DOT__freeEntries 
        = (0x1fU & ((IData)(0x10U) - (IData)(Top__DOT__reorderBuffer__DOT__usedEntries)));
    Top__DOT__reorderBuffer__DOT__moreThanOne = (0U 
                                                 != 
                                                 (0xfU 
                                                  & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeEntries) 
                                                     >> 1U)));
    Top__DOT__nextFreeSlots = (((IData)(Top__DOT__reorderBuffer__DOT__moreThanOne) 
                                << 1U) | (1U & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeEntries)));
    vlSelf->Top__DOT__rstBus2 = 0U;
    vlSelf->Top__DOT__rstBus1 = 0U;
    vlSelf->Top__DOT__rstBus3 = 0U;
    if (vlSelf->Top__DOT__redirect) {
        vlSelf->Top__DOT__freeTag1 = (0xfU & ((IData)(1U) 
                                              + (IData)(Top__DOT__reorderBuffer__DOT____VdfgTmp_hce32cc98__0)));
        if (((1U < (IData)(Top__DOT__reorderBuffer__DOT__flushCount)) 
             & ((0U != (IData)(Top__DOT__reorderBuffer__DOT__flushDest2)) 
                & ((IData)(Top__DOT__reorderBuffer__DOT__flushDest1) 
                   != (IData)(Top__DOT__reorderBuffer__DOT__flushDest2))))) {
            vlSelf->Top__DOT__rstBus2 = (1U | (IData)(vlSelf->Top__DOT__rstBus2));
            vlSelf->Top__DOT__rstBus2 = ((1U & (IData)(vlSelf->Top__DOT__rstBus2)) 
                                         | (((IData)(Top__DOT__reorderBuffer__DOT__flushDest2) 
                                             << 7U) 
                                            | (((IData)(Top__DOT__reorderBuffer__DOT__minIndex2) 
                                                << 3U) 
                                               | (((IData)(Top__DOT__reorderBuffer__DOT__found2)
                                                    ? 2U
                                                    : 3U) 
                                                  << 1U))));
        }
        if (((0U < (IData)(Top__DOT__reorderBuffer__DOT__flushCount)) 
             & (0U != (IData)(Top__DOT__reorderBuffer__DOT__flushDest1)))) {
            vlSelf->Top__DOT__rstBus1 = (1U | (IData)(vlSelf->Top__DOT__rstBus1));
            vlSelf->Top__DOT__rstBus1 = ((7U & (IData)(vlSelf->Top__DOT__rstBus1)) 
                                         | (((IData)(Top__DOT__reorderBuffer__DOT__flushDest1) 
                                             << 7U) 
                                            | ((IData)(Top__DOT__reorderBuffer__DOT__minIndex1) 
                                               << 3U)));
            vlSelf->Top__DOT__rstBus1 = ((0xff9U & (IData)(vlSelf->Top__DOT__rstBus1)) 
                                         | (((IData)(Top__DOT__reorderBuffer__DOT__found1)
                                              ? (((
                                                   ((IData)(Top__DOT__reorderBuffer__DOT__minIndex1) 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(
                                                               (vlSelf->Top__DOT__resolvedInstruction1 
                                                                >> 1U)))) 
                                                   & (IData)(vlSelf->Top__DOT__resolvedInstruction1)) 
                                                  | (((IData)(Top__DOT__reorderBuffer__DOT__minIndex1) 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(
                                                                 (vlSelf->Top__DOT__resolvedInstruction2 
                                                                  >> 1U)))) 
                                                     & (IData)(vlSelf->Top__DOT__resolvedInstruction2)))
                                                  ? 3U
                                                  : 2U)
                                              : 3U) 
                                            << 1U));
        }
        if (((2U < (IData)(Top__DOT__reorderBuffer__DOT__flushCount)) 
             & ((0U != (IData)(Top__DOT__reorderBuffer__DOT__flushDest3)) 
                & (((IData)(Top__DOT__reorderBuffer__DOT__flushDest1) 
                    != (IData)(Top__DOT__reorderBuffer__DOT__flushDest3)) 
                   & ((IData)(Top__DOT__reorderBuffer__DOT__flushDest2) 
                      != (IData)(Top__DOT__reorderBuffer__DOT__flushDest3)))))) {
            vlSelf->Top__DOT__rstBus3 = (1U | (IData)(vlSelf->Top__DOT__rstBus3));
            vlSelf->Top__DOT__rstBus3 = ((1U & (IData)(vlSelf->Top__DOT__rstBus3)) 
                                         | (((IData)(Top__DOT__reorderBuffer__DOT__flushDest3) 
                                             << 7U) 
                                            | (((IData)(Top__DOT__reorderBuffer__DOT__minIndex3) 
                                                << 3U) 
                                               | (((IData)(Top__DOT__reorderBuffer__DOT__found3)
                                                    ? 2U
                                                    : 3U) 
                                                  << 1U))));
        }
    } else {
        vlSelf->Top__DOT__freeTag1 = (0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer));
    }
    Top__DOT__decodeIssue__DOT__block1 = 0U;
    Top__DOT__decodeIssue__DOT__block2 = 0U;
    vlSelf->Top__DOT__instructionConsumed1 = 0U;
    vlSelf->Top__DOT__instructionConsumed2 = 0U;
    if (vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid) {
        if ((1U & (~ (IData)(((0x2000000U == (0x6000000U 
                                              & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U])) 
                              & (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                                  == (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                               >> 2U))) 
                                 | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                                    == (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                 >> 7U))))))))) {
            if ((((0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                            >> 2U)) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)) 
                 & (0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)))) {
                vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable 
                    = (1U | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable));
            }
            if ((((0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                            >> 7U)) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)) 
                 & (0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1)))) {
                vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable 
                    = (2U | (IData)(vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable));
            }
        }
        if (vlSelf->Top__DOT__decodeIssue__DOT__illegal1) {
            Top__DOT__decodeIssue__DOT__block1 = 1U;
        }
        if ((1U != (IData)(Top__DOT__nextFreeSlots))) {
            if ((0U == (IData)(Top__DOT__nextFreeSlots))) {
                Top__DOT__decodeIssue__DOT__block1 = 1U;
            }
        }
        if (vlSelf->Top__DOT__redirect) {
            Top__DOT__decodeIssue__DOT__block1 = 1U;
        }
        if ((((IData)(vlSelf->Top__DOT__upperInFlightLoad1) 
              | (IData)(vlSelf->Top__DOT__upperInFlightLoad2)) 
             | (IData)(vlSelf->Top__DOT__destRegLoad1))) {
            Top__DOT__decodeIssue__DOT__block1 = 1U;
        }
        if (vlSelf->Top__DOT__decodeIssue__DOT__illegal2) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__decodeIssue__DOT__illegal1) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((0U != (3U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                          >> 0x19U)))) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
             == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((IData)(((0x2000000U == (0x6000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U])) 
                     & (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                         == (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                      >> 2U))) | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                      >> 7U))))))) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__decodeIssue__DOT__internalBadData) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((1U == (IData)(Top__DOT__nextFreeSlots))) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        } else if ((0U == (IData)(Top__DOT__nextFreeSlots))) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__redirect) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((((IData)(vlSelf->Top__DOT__upperInFlightLoad1) 
              | (IData)(vlSelf->Top__DOT__upperInFlightLoad2)) 
             | (IData)(vlSelf->Top__DOT__destRegLoad1))) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((((IData)(vlSelf->Top__DOT__lowerInFlightLoad1) 
              | (IData)(vlSelf->Top__DOT__lowerInFlightLoad2)) 
             | (IData)(vlSelf->Top__DOT__destRegLoad2))) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (((((0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                         >> 2U)) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)) 
              & (0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) 
             | (((0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[2U] 
                           >> 7U)) == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)) 
                & (0U != (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))))) {
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (((0U != (3U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                           >> 0x19U))) & (~ (IData)(vlSelf->Top__DOT__memFreeSlot)))) {
            Top__DOT__decodeIssue__DOT__block1 = 1U;
            Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
    } else {
        Top__DOT__decodeIssue__DOT__block1 = 1U;
        Top__DOT__decodeIssue__DOT__block2 = 1U;
    }
    if ((1U & ((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->Top__DOT__redirect))))) {
        if ((1U & ((~ (IData)(Top__DOT__decodeIssue__DOT__block1)) 
                   & (~ (IData)(Top__DOT__decodeIssue__DOT__block2))))) {
            vlSelf->Top__DOT__instructionConsumed1 = 1U;
            vlSelf->Top__DOT__instructionConsumed2 = 1U;
        } else if ((1U & (~ (IData)(Top__DOT__decodeIssue__DOT__block1)))) {
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
    vlSelf->Top__DOT__instructionPacket1 = 0ULL;
    Top__DOT__decodeIssue__DOT__standardOp1 = (IData)(
                                                      (0U 
                                                       == 
                                                       (0x6386000U 
                                                        & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U])));
    vlSelf->Top__DOT__instructionPacket2 = 0ULL;
    Top__DOT__decodeIssue__DOT__standardOp2 = (IData)(
                                                      (0U 
                                                       == 
                                                       (0x6386000U 
                                                        & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U])));
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
            = ((0x3ffffffU & vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]) 
               | ((IData)(((0x7fffffffffe0ULL & (((QData)((IData)(
                                                                  vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])) 
                                                  << 0x23U) 
                                                 | (0xffffffffffffffe0ULL 
                                                    & ((QData)((IData)(
                                                                       vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U])) 
                                                       << 3U)))) 
                           | (QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)))) 
                  << 0x1aU));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[1U] 
            = (((IData)(((0x7fffffffffe0ULL & (((QData)((IData)(
                                                                vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])) 
                                                << 0x23U) 
                                               | (0xffffffffffffffe0ULL 
                                                  & ((QData)((IData)(
                                                                     vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U])) 
                                                     << 3U)))) 
                         | (QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2)))) 
                >> 6U) | ((IData)((((0x7fffffffffe0ULL 
                                     & (((QData)((IData)(
                                                         vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])) 
                                         << 0x23U) 
                                        | (0xffffffffffffffe0ULL 
                                           & ((QData)((IData)(
                                                              vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U])) 
                                              << 3U)))) 
                                    | (QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) 
                                   >> 0x20U)) << 0x1aU));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[2U] 
            = (((0x3fffe00U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                               >> 3U)) | ((IData)((
                                                   ((0x7fffffffffe0ULL 
                                                     & (((QData)((IData)(
                                                                         vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U])) 
                                                         << 0x23U) 
                                                        | (0xffffffffffffffe0ULL 
                                                           & ((QData)((IData)(
                                                                              vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U])) 
                                                              << 3U)))) 
                                                    | (QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) 
                                                   >> 0x20U)) 
                                          >> 6U)) | 
               (0xfc000000U & ((vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[3U] 
                                << 0x1dU) | (0x1c000000U 
                                             & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                >> 3U)))));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[3U] 
            = (0x1ffU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[3U] 
                         >> 3U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = ((0x1fffffffU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
               | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                  << 0x1dU));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[1U] 
            = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[1U]) 
               | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                  >> 3U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
            = ((0xfc01ffffU & vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]) 
               | (0xfffe0000U & ((0x3000000U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                                >> 3U)) 
                                 | (0xfe0000U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                                 << 2U)))));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = ((0xffffe1ffU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
               | ((IData)(vlSelf->Top__DOT__freeTag1) 
                  << 9U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
            = ((0xfffe007fU & vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]) 
               | (0xffffff80U & ((0x18000U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                              << 2U)) 
                                 | ((0x7800U & (((IData)(1U) 
                                                 + (IData)(vlSelf->Top__DOT__freeTag1)) 
                                                << 0xbU)) 
                                    | (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable) 
                                        << 9U) | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__staleVector2) 
                                                  << 7U))))));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = ((0xffffff81U & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
               | ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                  << 1U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
            = ((0xffffff81U & vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]) 
               | ((IData)(vlSelf->Top__DOT__oldLowerStatus) 
                  << 1U));
        if (((((0xfU & ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                        >> 1U)) == (0xfU & (IData)(
                                                   (vlSelf->Top__DOT__resolvedInstruction1 
                                                    >> 1U)))) 
              & (IData)(vlSelf->Top__DOT__resolvedInstruction1)) 
             | (((0xfU & ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                          >> 1U)) == (0xfU & (IData)(
                                                     (vlSelf->Top__DOT__resolvedInstruction2 
                                                      >> 1U)))) 
                & (IData)(vlSelf->Top__DOT__resolvedInstruction2)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
                = (0x40U | vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
            vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
                = (2U | vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
        } else if (((((0xfU & ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                               >> 1U)) == (0xfU & (IData)(
                                                          (vlSelf->Top__DOT__resultPayload1 
                                                           >> 0x26U)))) 
                     & (IData)(vlSelf->Top__DOT__resultPayload1)) 
                    | (((0xfU & ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                                 >> 1U)) == (0xfU & (IData)(
                                                            (vlSelf->Top__DOT__resultPayload2 
                                                             >> 0x26U)))) 
                       & (IData)(vlSelf->Top__DOT__resultPayload2)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
                = (0x40U | vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
            vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
                = (0xfffffffdU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
        }
        if (((((0xfU & ((IData)(vlSelf->Top__DOT__oldLowerStatus) 
                        >> 1U)) == (0xfU & (IData)(
                                                   (vlSelf->Top__DOT__resolvedInstruction1 
                                                    >> 1U)))) 
              & (IData)(vlSelf->Top__DOT__resolvedInstruction1)) 
             | (((0xfU & ((IData)(vlSelf->Top__DOT__oldLowerStatus) 
                          >> 1U)) == (0xfU & (IData)(
                                                     (vlSelf->Top__DOT__resolvedInstruction2 
                                                      >> 1U)))) 
                & (IData)(vlSelf->Top__DOT__resolvedInstruction2)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
                = (0x40U | vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]);
            vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
                = (2U | vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]);
        } else if (((((0xfU & ((IData)(vlSelf->Top__DOT__oldLowerStatus) 
                               >> 1U)) == (0xfU & (IData)(
                                                          (vlSelf->Top__DOT__resultPayload1 
                                                           >> 0x26U)))) 
                     & (IData)(vlSelf->Top__DOT__resultPayload1)) 
                    | (((0xfU & ((IData)(vlSelf->Top__DOT__oldLowerStatus) 
                                 >> 1U)) == (0xfU & (IData)(
                                                            (vlSelf->Top__DOT__resultPayload2 
                                                             >> 0x26U)))) 
                       & (IData)(vlSelf->Top__DOT__resultPayload2)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
                = (0x40U | vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]);
            vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
                = (0xfffffffdU & vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]);
        }
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = ((0xfffffe7fU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
               | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__staleVector1) 
                  << 7U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U] 
            = (1U | vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload[0U]);
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = (1U | vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
        vlSelf->Top__DOT__instructionPacket1 = ((1ULL 
                                                 & vlSelf->Top__DOT__instructionPacket1) 
                                                | (((QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__PC1)) 
                                                    << 0xbU) 
                                                   | ((QData)((IData)(
                                                                      (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                                                                        << 5U) 
                                                                       | (((IData)(vlSelf->Top__DOT__freeTag1) 
                                                                           << 1U) 
                                                                          | (IData)(Top__DOT__decodeIssue__DOT__standardOp1))))) 
                                                      << 1U)));
        vlSelf->Top__DOT__instructionPacket1 = (1ULL 
                                                | vlSelf->Top__DOT__instructionPacket1);
        vlSelf->Top__DOT__instructionPacket2 = ((1ULL 
                                                 & vlSelf->Top__DOT__instructionPacket2) 
                                                | (((QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__PC2)) 
                                                    << 0xbU) 
                                                   | ((QData)((IData)(
                                                                      (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2) 
                                                                        << 5U) 
                                                                       | ((0x1eU 
                                                                           & (((IData)(1U) 
                                                                               + (IData)(vlSelf->Top__DOT__freeTag1)) 
                                                                              << 1U)) 
                                                                          | (IData)(Top__DOT__decodeIssue__DOT__standardOp2))))) 
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
            = ((0x1fffffffU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
               | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                  << 0x1dU));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[1U] 
            = ((0xfffffffcU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[1U]) 
               | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                  >> 3U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = ((0xfffffe01U & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
               | (0xfffffffeU & (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__staleVector1) 
                                  << 7U) | ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                                            << 1U))));
        if (((((0xfU & ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                        >> 1U)) == (0xfU & (IData)(
                                                   (vlSelf->Top__DOT__resolvedInstruction1 
                                                    >> 1U)))) 
              & (IData)(vlSelf->Top__DOT__resolvedInstruction1)) 
             | (((0xfU & ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                          >> 1U)) == (0xfU & (IData)(
                                                     (vlSelf->Top__DOT__resolvedInstruction2 
                                                      >> 1U)))) 
                & (IData)(vlSelf->Top__DOT__resolvedInstruction2)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
                = (0x40U | vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
            vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
                = (2U | vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
        } else if (((((0xfU & ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                               >> 1U)) == (0xfU & (IData)(
                                                          (vlSelf->Top__DOT__resultPayload1 
                                                           >> 0x26U)))) 
                     & (IData)(vlSelf->Top__DOT__resultPayload1)) 
                    | (((0xfU & ((IData)(vlSelf->Top__DOT__oldUpperStatus) 
                                 >> 1U)) == (0xfU & (IData)(
                                                            (vlSelf->Top__DOT__resultPayload2 
                                                             >> 0x26U)))) 
                       & (IData)(vlSelf->Top__DOT__resultPayload2)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
                = (0x40U | vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
            vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
                = (0xfffffffdU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
        }
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = ((0xffffe1ffU & vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]) 
               | ((IData)(vlSelf->Top__DOT__freeTag1) 
                  << 9U));
        vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U] 
            = (1U | vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload[0U]);
        vlSelf->Top__DOT__instructionPacket1 = ((1ULL 
                                                 & vlSelf->Top__DOT__instructionPacket1) 
                                                | (((QData)((IData)(vlSelf->Top__DOT__decodeIssue__DOT__PC1)) 
                                                    << 0xbU) 
                                                   | ((QData)((IData)(
                                                                      (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                                                                        << 5U) 
                                                                       | (((IData)(vlSelf->Top__DOT__freeTag1) 
                                                                           << 1U) 
                                                                          | (IData)(Top__DOT__decodeIssue__DOT__standardOp1))))) 
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
    vlSelf->Top__DOT__reorderBuffer__DOT__nextTailPointer 
        = (0x1fU & (((IData)(vlSelf->Top__DOT__redirect)
                      ? (IData)(Top__DOT__reorderBuffer__DOT__redirectPointer)
                      : (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer)) 
                    + ((1U & (IData)(vlSelf->Top__DOT__instructionPacket1)) 
                       + (1U & (IData)(vlSelf->Top__DOT__instructionPacket2)))));
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
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge clock)\n");
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
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge clock)\n");
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
    vlSelf->Top__DOT__resolvedInstruction1 = VL_RAND_RESET_Q(42);
    vlSelf->Top__DOT__resolvedInstruction2 = VL_RAND_RESET_Q(42);
    vlSelf->Top__DOT__upperROBData1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__upperROBData2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__lowerROBData1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__lowerROBData2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__freeTag1 = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__rstBus1 = VL_RAND_RESET_I(12);
    vlSelf->Top__DOT__rstBus2 = VL_RAND_RESET_I(12);
    vlSelf->Top__DOT__rstBus3 = VL_RAND_RESET_I(12);
    vlSelf->Top__DOT__upperSource1Status = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__upperSource2Status = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__lowerSource1Status = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__lowerSource2Status = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__oldLowerStatus = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__oldUpperStatus = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__upperInFlightLoad1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__upperInFlightLoad2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__lowerInFlightLoad1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__lowerInFlightLoad2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__destRegLoad1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__destRegLoad2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__instructionConsumed1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__instructionConsumed2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__requestPC1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__requestPC2 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(108, vlSelf->Top__DOT__payload1);
    VL_RAND_RESET_W(105, vlSelf->Top__DOT__payload2);
    vlSelf->Top__DOT__instructionPacket1 = VL_RAND_RESET_Q(43);
    vlSelf->Top__DOT__instructionPacket2 = VL_RAND_RESET_Q(43);
    VL_RAND_RESET_W(120, vlSelf->Top__DOT__exPayload1);
    VL_RAND_RESET_W(117, vlSelf->Top__DOT__exPayload2);
    vlSelf->Top__DOT__upperSourceData1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__upperSourceData2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__lowerSourceData1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__lowerSourceData2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__resultPayload1 = VL_RAND_RESET_Q(42);
    vlSelf->Top__DOT__resultPayload2 = VL_RAND_RESET_Q(42);
    VL_RAND_RESET_W(78, vlSelf->Top__DOT__memPayload);
    vlSelf->Top__DOT__redirect = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__redirectVector = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__redirect1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__instruction1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__instruction2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__programCounter = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__completedMemory = VL_RAND_RESET_Q(42);
    VL_RAND_RESET_W(71, vlSelf->Top__DOT__memBusOut);
    vlSelf->Top__DOT__memFreeSlot = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__lowFetchData);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__highFetchData);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_RAND_RESET_W(78, vlSelf->Top__DOT__memoryQueue__DOT__queueEntry[__Vi0]);
    }
    vlSelf->Top__DOT__memoryQueue__DOT__tailPointer = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__memoryQueue__DOT__byteSelectTransform = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__memoryQueue__DOT__unnamedblk3__DOT__unnamedblk5__DOT__index = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->Top__DOT__placeholderDMEM__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__placeholderDMEM__DOT__requestPending = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__placeholderDMEM__DOT__latchedAddress = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__placeholderDMEM__DOT__latchedStoreData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__placeholderDMEM__DOT__latchedWriteEnable = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__placeholderDMEM__DOT__latchedByteSelect = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__placeholderDMEM__DOT__delayCounter = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__placeholderDMEM__DOT__validRequest = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__placeholderDMEM__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->Top__DOT__placeholderDMEM__DOT__unnamedblk2__DOT__wordIndex = VL_RAND_RESET_I(10);
    vlSelf->Top__DOT__placeholderDMEM__DOT__unnamedblk2__DOT__nextLoadData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__reorderBuffer__DOT__headPointer = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__nextTailPointer = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        VL_RAND_RESET_W(75, vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer[__Vi0]);
    }
    vlSelf->Top__DOT__reorderBuffer__DOT__freeEntries = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__entries = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 3; ++__Vi1) {
            vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable[__Vi0] = VL_RAND_RESET_I(7);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__registerFile__DOT__registerFile[__Vi0] = VL_RAND_RESET_I(32);
    }
    VL_RAND_RESET_W(120, vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1);
    VL_RAND_RESET_W(117, vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2);
    vlSelf->Top__DOT__operandSelect__DOT__debugCycle = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__execute__DOT__result1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__result2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__illegal1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(108, vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2);
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(108, vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1);
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(108, vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload);
    VL_RAND_RESET_W(105, vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload);
    vlSelf->Top__DOT__decodeIssue__DOT__IR1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__IR2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__PC1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__PC2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__postRedirectCounter = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__internalBadData = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__bypassEnable = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__decodeIssue__DOT__staleVector1 = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__decodeIssue__DOT__staleVector2 = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->Top__DOT__instructionMemory__DOT__memory[__Vi0]);
    }
    vlSelf->Top__DOT__instructionMemory__DOT__redirectAddress = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__instructionMemory__DOT__nextAddress = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
}
