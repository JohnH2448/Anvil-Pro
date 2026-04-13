// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__2(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*1:0*/ Top__DOT__nextFreeSlots;
    Top__DOT__nextFreeSlots = 0;
    CData/*5:0*/ Top__DOT__reorderBuffer__DOT__usedEntries;
    Top__DOT__reorderBuffer__DOT__usedEntries = 0;
    CData/*5:0*/ Top__DOT__reorderBuffer__DOT__freeEntries;
    Top__DOT__reorderBuffer__DOT__freeEntries = 0;
    CData/*0:0*/ Top__DOT__reorderBuffer__DOT__moreThanOne;
    Top__DOT__reorderBuffer__DOT__moreThanOne = 0;
    CData/*1:0*/ Top__DOT__reorderBuffer__DOT__flushCount;
    Top__DOT__reorderBuffer__DOT__flushCount = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__minIndex3;
    Top__DOT__reorderBuffer__DOT__minIndex3 = 0;
    CData/*4:0*/ Top__DOT__reorderBuffer__DOT__minValue3;
    Top__DOT__reorderBuffer__DOT__minValue3 = 0;
    CData/*0:0*/ Top__DOT__reorderBuffer__DOT__found3;
    Top__DOT__reorderBuffer__DOT__found3 = 0;
    IData/*31:0*/ Top__DOT__operandSelect__DOT__upperOperand1;
    Top__DOT__operandSelect__DOT__upperOperand1 = 0;
    IData/*31:0*/ Top__DOT__operandSelect__DOT__upperOperand2;
    Top__DOT__operandSelect__DOT__upperOperand2 = 0;
    IData/*31:0*/ Top__DOT__operandSelect__DOT__lowerOperand1;
    Top__DOT__operandSelect__DOT__lowerOperand1 = 0;
    IData/*31:0*/ Top__DOT__operandSelect__DOT__lowerOperand2;
    Top__DOT__operandSelect__DOT__lowerOperand2 = 0;
    // Body
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xcU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xcU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xcU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0xcU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xdU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xdU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xdU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0xdU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xeU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xeU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xeU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0xeU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0xfU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0xfU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0xfU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0xfU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x10U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x10U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x10U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x10U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x11U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x11U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x11U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x11U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x12U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x12U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x12U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x12U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x13U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x13U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x13U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x13U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x14U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x14U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x14U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x14U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x15U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x15U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x15U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x15U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x16U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x16U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x16U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x16U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x17U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x17U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x17U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x17U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x18U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x18U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x18U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x18U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x19U][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x19U] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x19U];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x19U;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1aU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1aU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1aU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x1aU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1bU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1bU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1bU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x1bU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1cU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1cU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1cU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x1cU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1dU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1dU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1dU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x1dU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1eU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1eU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1eU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x1eU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1fU][1U]) {
        if ((1U & ((~ (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1fU] < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minValue2))))) {
            vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1fU];
            vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = 0x1fU;
            vlSelf->Top__DOT__reorderBuffer__DOT__found2 = 1U;
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
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x10U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x10U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x10U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x10U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x11U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x11U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x11U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x11U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x12U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x12U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x12U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x12U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x13U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x13U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x13U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x13U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x14U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x14U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x14U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x14U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x15U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x15U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x15U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x15U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x16U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x16U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x16U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x16U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x17U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x17U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x17U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x17U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x18U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x18U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x18U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x18U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x19U][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x19U] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x19U];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x19U;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1aU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1aU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1aU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x1aU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1bU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1bU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1bU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x1bU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1cU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1cU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1cU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x1cU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1dU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1dU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1dU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x1dU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1eU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1eU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1eU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x1eU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    if (vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid
        [0x1fU][2U]) {
        if ((1U & ((~ (IData)(Top__DOT__reorderBuffer__DOT__found3)) 
                   | (vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                      [0x1fU] < (IData)(Top__DOT__reorderBuffer__DOT__minValue3))))) {
            Top__DOT__reorderBuffer__DOT__minValue3 
                = vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid
                [0x1fU];
            Top__DOT__reorderBuffer__DOT__minIndex3 = 0x1fU;
            Top__DOT__reorderBuffer__DOT__found3 = 1U;
        }
    }
    Top__DOT__reorderBuffer__DOT__flushCount = (3U 
                                                & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer) 
                                                   - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__redirectPointer)));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[2U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[3U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[4U] = 0U;
    Top__DOT__operandSelect__DOT__lowerOperand1 = 0U;
    Top__DOT__operandSelect__DOT__lowerOperand2 = 0U;
    if ((0U == (0x1fU & (vlSelf->Top__DOT__payload2[2U] 
                         >> 3U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 = 0U;
    } else if ((2U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = ((0U != (0x1fU & (vlSelf->Top__DOT__payload2[2U] 
                                >> 3U))) ? vlSelf->Top__DOT__registerFile__DOT__registerFile
               [(0x1fU & (vlSelf->Top__DOT__payload2[2U] 
                          >> 3U))] : 0U);
    } else if ((0x80U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                [(0x1fU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status) 
                           >> 2U))][1U] << 0x14U) | 
               (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                [(0x1fU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status) 
                           >> 2U))][0U] >> 0xcU));
    } else if ((1U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status))) {
        if (((IData)(vlSelf->Top__DOT__completedMemory) 
             & ((0x1fU & (IData)((vlSelf->Top__DOT__completedMemory 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status) 
                                                     >> 2U))))) {
            Top__DOT__operandSelect__DOT__lowerOperand1 
                = (IData)((vlSelf->Top__DOT__completedMemory 
                           >> 6U));
        }
    } else if ((((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                   >> 0x26U))) == (0x1fU 
                                                   & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status) 
                                                      >> 2U))) 
                & vlSelf->Top__DOT__exPayload2[0U])) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status) 
                                                     >> 2U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    if ((0U == (0x1fU & (vlSelf->Top__DOT__payload2[2U] 
                         >> 8U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 = 0U;
    } else if ((2U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = ((0U != (0x1fU & (vlSelf->Top__DOT__payload2[2U] 
                                >> 8U))) ? vlSelf->Top__DOT__registerFile__DOT__registerFile
               [(0x1fU & (vlSelf->Top__DOT__payload2[2U] 
                          >> 8U))] : 0U);
    } else if ((0x80U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                [(0x1fU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status) 
                           >> 2U))][1U] << 0x14U) | 
               (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                [(0x1fU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status) 
                           >> 2U))][0U] >> 0xcU));
    } else if ((1U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status))) {
        if (((IData)(vlSelf->Top__DOT__completedMemory) 
             & ((0x1fU & (IData)((vlSelf->Top__DOT__completedMemory 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status) 
                                                     >> 2U))))) {
            Top__DOT__operandSelect__DOT__lowerOperand2 
                = (IData)((vlSelf->Top__DOT__completedMemory 
                           >> 6U));
        }
    } else if ((((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                   >> 0x26U))) == (0x1fU 
                                                   & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status) 
                                                      >> 2U))) 
                & vlSelf->Top__DOT__exPayload2[0U])) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status) 
                                                     >> 2U)))) {
        Top__DOT__operandSelect__DOT__lowerOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] 
        = ((0x7fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U]) 
           | ((IData)(((0x20000000U & vlSelf->Top__DOT__payload2[0U])
                        ? ((0x10000000U & vlSelf->Top__DOT__payload2[0U])
                            ? (QData)((IData)(((vlSelf->Top__DOT__payload2[2U] 
                                                << 0x1dU) 
                                               | (vlSelf->Top__DOT__payload2[1U] 
                                                  >> 3U))))
                            : (((QData)((IData)(((vlSelf->Top__DOT__payload2[3U] 
                                                  << 0x13U) 
                                                 | (vlSelf->Top__DOT__payload2[2U] 
                                                    >> 0xdU)))) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[2U] 
                                                              << 0x1dU) 
                                                             | (vlSelf->Top__DOT__payload2[1U] 
                                                                >> 3U))))))
                        : ((0x10000000U & vlSelf->Top__DOT__payload2[0U])
                            ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload2[2U] 
                                                              << 0x1dU) 
                                                             | (vlSelf->Top__DOT__payload2[1U] 
                                                                >> 3U)))))
                            : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2)))))) 
              << 0x17U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[2U] 
        = (((IData)(((0x20000000U & vlSelf->Top__DOT__payload2[0U])
                      ? ((0x10000000U & vlSelf->Top__DOT__payload2[0U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload2[2U] 
                                              << 0x1dU) 
                                             | (vlSelf->Top__DOT__payload2[1U] 
                                                >> 3U))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload2[3U] 
                                                << 0x13U) 
                                               | (vlSelf->Top__DOT__payload2[2U] 
                                                  >> 0xdU)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[2U] 
                                                            << 0x1dU) 
                                                           | (vlSelf->Top__DOT__payload2[1U] 
                                                              >> 3U))))))
                      : ((0x10000000U & vlSelf->Top__DOT__payload2[0U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[2U] 
                                                            << 0x1dU) 
                                                           | (vlSelf->Top__DOT__payload2[1U] 
                                                              >> 3U)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2)))))) 
            >> 9U) | ((IData)((((0x20000000U & vlSelf->Top__DOT__payload2[0U])
                                 ? ((0x10000000U & 
                                     vlSelf->Top__DOT__payload2[0U])
                                     ? (QData)((IData)(
                                                       ((vlSelf->Top__DOT__payload2[2U] 
                                                         << 0x1dU) 
                                                        | (vlSelf->Top__DOT__payload2[1U] 
                                                           >> 3U))))
                                     : (((QData)((IData)(
                                                         ((vlSelf->Top__DOT__payload2[3U] 
                                                           << 0x13U) 
                                                          | (vlSelf->Top__DOT__payload2[2U] 
                                                             >> 0xdU)))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[2U] 
                                                            << 0x1dU) 
                                                           | (vlSelf->Top__DOT__payload2[1U] 
                                                              >> 3U))))))
                                 : ((0x10000000U & 
                                     vlSelf->Top__DOT__payload2[0U])
                                     ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload2[2U] 
                                                            << 0x1dU) 
                                                           | (vlSelf->Top__DOT__payload2[1U] 
                                                              >> 3U)))))
                                     : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                         << 0x20U) 
                                        | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2))))) 
                               >> 0x20U)) << 0x17U));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[3U] 
        = ((0xff800000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[3U]) 
           | ((IData)((((0x20000000U & vlSelf->Top__DOT__payload2[0U])
                         ? ((0x10000000U & vlSelf->Top__DOT__payload2[0U])
                             ? (QData)((IData)(((vlSelf->Top__DOT__payload2[2U] 
                                                 << 0x1dU) 
                                                | (vlSelf->Top__DOT__payload2[1U] 
                                                   >> 3U))))
                             : (((QData)((IData)(((
                                                   vlSelf->Top__DOT__payload2[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->Top__DOT__payload2[2U] 
                                                     >> 0xdU)))) 
                                 << 0x20U) | (QData)((IData)(
                                                             ((vlSelf->Top__DOT__payload2[2U] 
                                                               << 0x1dU) 
                                                              | (vlSelf->Top__DOT__payload2[1U] 
                                                                 >> 3U))))))
                         : ((0x10000000U & vlSelf->Top__DOT__payload2[0U])
                             ? (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                 << 0x20U) | (QData)((IData)(
                                                             ((vlSelf->Top__DOT__payload2[2U] 
                                                               << 0x1dU) 
                                                              | (vlSelf->Top__DOT__payload2[1U] 
                                                                 >> 3U)))))
                             : (((QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand1)) 
                                 << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__lowerOperand2))))) 
                       >> 0x20U)) >> 9U));
    if ((0U != (3U & (vlSelf->Top__DOT__payload2[0U] 
                      >> 0x13U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
            = ((0x7fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload2[3U] 
                                   << 0x13U) | (vlSelf->Top__DOT__payload2[2U] 
                                                >> 0xdU))) 
                  << 0x17U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] 
            = ((0xff800000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload2[3U] 
                                   << 0x13U) | (vlSelf->Top__DOT__payload2[2U] 
                                                >> 0xdU))) 
                  >> 9U));
    } else if ((0U != (7U & (vlSelf->Top__DOT__payload2[0U] 
                             >> 0x19U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
            = ((0x7fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
               | ((((vlSelf->Top__DOT__payload2[3U] 
                     << 0x13U) | (vlSelf->Top__DOT__payload2[2U] 
                                  >> 0xdU)) + ((vlSelf->Top__DOT__payload2[2U] 
                                                << 0x1dU) 
                                               | (vlSelf->Top__DOT__payload2[1U] 
                                                  >> 3U))) 
                  << 0x17U));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U] 
            = ((0xff800000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[1U]) 
               | ((((vlSelf->Top__DOT__payload2[3U] 
                     << 0x13U) | (vlSelf->Top__DOT__payload2[2U] 
                                  >> 0xdU)) + ((vlSelf->Top__DOT__payload2[2U] 
                                                << 0x1dU) 
                                               | (vlSelf->Top__DOT__payload2[1U] 
                                                  >> 3U))) 
                  >> 9U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xff8001ffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (0xfffffe00U & ((0x7c0000U & ((vlSelf->Top__DOT__payload2[1U] 
                                            << 0x14U) 
                                           | (0xc0000U 
                                              & (vlSelf->Top__DOT__payload2[0U] 
                                                 >> 0xcU)))) 
                             | ((0x3f000U & (vlSelf->Top__DOT__payload2[0U] 
                                             >> 7U)) 
                                | (0xe00U & (vlSelf->Top__DOT__payload2[0U] 
                                             >> 0x10U))))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xfffffe0fU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (0x1f0U & (vlSelf->Top__DOT__payload2[0U] 
                        >> 0xaU)));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xfffffffdU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (2U & vlSelf->Top__DOT__payload2[0U]));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[3U] 
        = ((0x7fffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[3U]) 
           | (0xff800000U & (vlSelf->Top__DOT__payload2[2U] 
                             << 0xaU)));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[4U] 
        = (0x7fffffU & ((0x7ffc00U & (vlSelf->Top__DOT__payload2[3U] 
                                      << 0xaU)) | (
                                                   vlSelf->Top__DOT__payload2[2U] 
                                                   >> 0x16U)));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xfffffffeU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | ((1U & ((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->Top__DOT__redirect)))) 
              && (1U & vlSelf->Top__DOT__payload2[0U])));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U] 
        = ((0xfffffff3U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2[0U]) 
           | (0xcU & (vlSelf->Top__DOT__payload2[0U] 
                      >> 0xaU)));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[2U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[3U] = 0U;
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[4U] = 0U;
    Top__DOT__operandSelect__DOT__upperOperand1 = 0U;
    Top__DOT__operandSelect__DOT__upperOperand2 = 0U;
    if ((0U == (0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                         >> 8U)))) {
        Top__DOT__operandSelect__DOT__upperOperand1 = 0U;
    } else if ((2U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = ((0U != (0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                                >> 8U))) ? vlSelf->Top__DOT__registerFile__DOT__registerFile
               [(0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                          >> 8U))] : 0U);
    } else if ((0x80U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                [(0x1fU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status) 
                           >> 2U))][1U] << 0x14U) | 
               (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                [(0x1fU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status) 
                           >> 2U))][0U] >> 0xcU));
    } else if ((1U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status))) {
        if (((IData)(vlSelf->Top__DOT__completedMemory) 
             & ((0x1fU & (IData)((vlSelf->Top__DOT__completedMemory 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status) 
                                                     >> 2U))))) {
            Top__DOT__operandSelect__DOT__upperOperand1 
                = (IData)((vlSelf->Top__DOT__completedMemory 
                           >> 6U));
        }
    } else if ((((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                   >> 0x26U))) == (0x1fU 
                                                   & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status) 
                                                      >> 2U))) 
                & vlSelf->Top__DOT__exPayload2[0U])) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status) 
                                                     >> 2U)))) {
        Top__DOT__operandSelect__DOT__upperOperand1 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    if ((0U == (0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                         >> 0xdU)))) {
        Top__DOT__operandSelect__DOT__upperOperand2 = 0U;
    } else if ((2U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = ((0U != (0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                                >> 0xdU))) ? vlSelf->Top__DOT__registerFile__DOT__registerFile
               [(0x1fU & (vlSelf->Top__DOT__payload1[2U] 
                          >> 0xdU))] : 0U);
    } else if ((0x80U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = ((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                [(0x1fU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status) 
                           >> 2U))][1U] << 0x14U) | 
               (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                [(0x1fU & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status) 
                           >> 2U))][0U] >> 0xcU));
    } else if ((1U & (IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status))) {
        if (((IData)(vlSelf->Top__DOT__completedMemory) 
             & ((0x1fU & (IData)((vlSelf->Top__DOT__completedMemory 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status) 
                                                     >> 2U))))) {
            Top__DOT__operandSelect__DOT__upperOperand2 
                = (IData)((vlSelf->Top__DOT__completedMemory 
                           >> 6U));
        }
    } else if ((((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload2 
                                   >> 0x26U))) == (0x1fU 
                                                   & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status) 
                                                      >> 2U))) 
                & vlSelf->Top__DOT__exPayload2[0U])) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload2 
                       >> 6U));
    } else if (((0x1fU & (IData)((vlSelf->Top__DOT__resultPayload1 
                                  >> 0x26U))) == (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status) 
                                                     >> 2U)))) {
        Top__DOT__operandSelect__DOT__upperOperand2 
            = (IData)((vlSelf->Top__DOT__resultPayload1 
                       >> 6U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
        = ((0x3ffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
           | ((IData)(((4U & vlSelf->Top__DOT__payload1[1U])
                        ? ((2U & vlSelf->Top__DOT__payload1[1U])
                            ? (QData)((IData)(((vlSelf->Top__DOT__payload1[2U] 
                                                << 0x18U) 
                                               | (vlSelf->Top__DOT__payload1[1U] 
                                                  >> 8U))))
                            : (((QData)((IData)(((vlSelf->Top__DOT__payload1[3U] 
                                                  << 0xeU) 
                                                 | (vlSelf->Top__DOT__payload1[2U] 
                                                    >> 0x12U)))) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload1[2U] 
                                                              << 0x18U) 
                                                             | (vlSelf->Top__DOT__payload1[1U] 
                                                                >> 8U))))))
                        : ((2U & vlSelf->Top__DOT__payload1[1U])
                            ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                << 0x20U) | (QData)((IData)(
                                                            ((vlSelf->Top__DOT__payload1[2U] 
                                                              << 0x18U) 
                                                             | (vlSelf->Top__DOT__payload1[1U] 
                                                                >> 8U)))))
                            : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2)))))) 
              << 0x1aU));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[2U] 
        = (((IData)(((4U & vlSelf->Top__DOT__payload1[1U])
                      ? ((2U & vlSelf->Top__DOT__payload1[1U])
                          ? (QData)((IData)(((vlSelf->Top__DOT__payload1[2U] 
                                              << 0x18U) 
                                             | (vlSelf->Top__DOT__payload1[1U] 
                                                >> 8U))))
                          : (((QData)((IData)(((vlSelf->Top__DOT__payload1[3U] 
                                                << 0xeU) 
                                               | (vlSelf->Top__DOT__payload1[2U] 
                                                  >> 0x12U)))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x18U) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 8U))))))
                      : ((2U & vlSelf->Top__DOT__payload1[1U])
                          ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x18U) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 8U)))))
                          : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                              << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2)))))) 
            >> 6U) | ((IData)((((4U & vlSelf->Top__DOT__payload1[1U])
                                 ? ((2U & vlSelf->Top__DOT__payload1[1U])
                                     ? (QData)((IData)(
                                                       ((vlSelf->Top__DOT__payload1[2U] 
                                                         << 0x18U) 
                                                        | (vlSelf->Top__DOT__payload1[1U] 
                                                           >> 8U))))
                                     : (((QData)((IData)(
                                                         ((vlSelf->Top__DOT__payload1[3U] 
                                                           << 0xeU) 
                                                          | (vlSelf->Top__DOT__payload1[2U] 
                                                             >> 0x12U)))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x18U) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 8U))))))
                                 : ((2U & vlSelf->Top__DOT__payload1[1U])
                                     ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((vlSelf->Top__DOT__payload1[2U] 
                                                            << 0x18U) 
                                                           | (vlSelf->Top__DOT__payload1[1U] 
                                                              >> 8U)))))
                                     : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                         << 0x20U) 
                                        | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2))))) 
                               >> 0x20U)) << 0x1aU));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[3U] 
        = ((0xfc000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[3U]) 
           | ((IData)((((4U & vlSelf->Top__DOT__payload1[1U])
                         ? ((2U & vlSelf->Top__DOT__payload1[1U])
                             ? (QData)((IData)(((vlSelf->Top__DOT__payload1[2U] 
                                                 << 0x18U) 
                                                | (vlSelf->Top__DOT__payload1[1U] 
                                                   >> 8U))))
                             : (((QData)((IData)(((
                                                   vlSelf->Top__DOT__payload1[3U] 
                                                   << 0xeU) 
                                                  | (vlSelf->Top__DOT__payload1[2U] 
                                                     >> 0x12U)))) 
                                 << 0x20U) | (QData)((IData)(
                                                             ((vlSelf->Top__DOT__payload1[2U] 
                                                               << 0x18U) 
                                                              | (vlSelf->Top__DOT__payload1[1U] 
                                                                 >> 8U))))))
                         : ((2U & vlSelf->Top__DOT__payload1[1U])
                             ? (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                 << 0x20U) | (QData)((IData)(
                                                             ((vlSelf->Top__DOT__payload1[2U] 
                                                               << 0x18U) 
                                                              | (vlSelf->Top__DOT__payload1[1U] 
                                                                 >> 8U)))))
                             : (((QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand1)) 
                                 << 0x20U) | (QData)((IData)(Top__DOT__operandSelect__DOT__upperOperand2))))) 
                       >> 0x20U)) >> 6U));
    if ((0U != (3U & (vlSelf->Top__DOT__payload1[0U] 
                      >> 0x13U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
            = ((0x3ffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload1[3U] 
                                   << 0xeU) | (vlSelf->Top__DOT__payload1[2U] 
                                               >> 0x12U))) 
                  << 0x1aU));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
            = ((0xfc000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
               | (((IData)(4U) + ((vlSelf->Top__DOT__payload1[3U] 
                                   << 0xeU) | (vlSelf->Top__DOT__payload1[2U] 
                                               >> 0x12U))) 
                  >> 6U));
    } else if ((0U != (7U & (vlSelf->Top__DOT__payload1[0U] 
                             >> 0x19U)))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
            = ((0x3ffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
               | ((((vlSelf->Top__DOT__payload1[3U] 
                     << 0xeU) | (vlSelf->Top__DOT__payload1[2U] 
                                 >> 0x12U)) + ((vlSelf->Top__DOT__payload1[2U] 
                                                << 0x18U) 
                                               | (vlSelf->Top__DOT__payload1[1U] 
                                                  >> 8U))) 
                  << 0x1aU));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
            = ((0xfc000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
               | ((((vlSelf->Top__DOT__payload1[3U] 
                     << 0xeU) | (vlSelf->Top__DOT__payload1[2U] 
                                 >> 0x12U)) + ((vlSelf->Top__DOT__payload1[2U] 
                                                << 0x18U) 
                                               | (vlSelf->Top__DOT__payload1[1U] 
                                                  >> 8U))) 
                  >> 6U));
    } else if ((2U == (3U & ((vlSelf->Top__DOT__payload1[1U] 
                              << 1U) | (vlSelf->Top__DOT__payload1[0U] 
                                        >> 0x1fU))))) {
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
            = ((0x3ffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
               | (Top__DOT__operandSelect__DOT__upperOperand2 
                  << 0x1aU));
        vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U] 
            = ((0xfc000000U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[1U]) 
               | (Top__DOT__operandSelect__DOT__upperOperand2 
                  >> 6U));
    }
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
        = ((0xfc000fffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
           | (0xfffff000U & ((0x3e00000U & (vlSelf->Top__DOT__payload1[1U] 
                                            << 0x12U)) 
                             | ((0x1f8000U & (vlSelf->Top__DOT__payload1[0U] 
                                              >> 4U)) 
                                | (0x7000U & (vlSelf->Top__DOT__payload1[0U] 
                                              >> 0xdU))))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
        = ((0xfffff001U & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
           | (0xfffffffeU & ((0xf80U & ((vlSelf->Top__DOT__payload1[1U] 
                                         << 0xbU) | 
                                        (0x780U & (
                                                   vlSelf->Top__DOT__payload1[0U] 
                                                   >> 0x15U)))) 
                             | ((0x7cU & (vlSelf->Top__DOT__payload1[0U] 
                                          >> 0xcU)) 
                                | (2U & vlSelf->Top__DOT__payload1[0U])))));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[3U] 
        = ((0x3ffffffU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[3U]) 
           | (0xfc000000U & (vlSelf->Top__DOT__payload1[2U] 
                             << 8U)));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[4U] 
        = (0x3ffffffU & ((0x3ffff00U & (vlSelf->Top__DOT__payload1[3U] 
                                        << 8U)) | (
                                                   vlSelf->Top__DOT__payload1[2U] 
                                                   >> 0x18U)));
    vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U] 
        = ((0xfffffffeU & vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1[0U]) 
           | ((1U & ((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->Top__DOT__redirect)))) 
              && (1U & vlSelf->Top__DOT__payload1[0U])));
    Top__DOT__reorderBuffer__DOT__usedEntries = (0x3fU 
                                                 & (((IData)(vlSelf->Top__DOT__redirect)
                                                      ? (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__redirectPointer)
                                                      : (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer)) 
                                                    - (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer)));
    Top__DOT__reorderBuffer__DOT__freeEntries = (0x3fU 
                                                 & ((IData)(0x20U) 
                                                    - (IData)(Top__DOT__reorderBuffer__DOT__usedEntries)));
    Top__DOT__reorderBuffer__DOT__moreThanOne = (0U 
                                                 != 
                                                 (0x1fU 
                                                  & ((IData)(Top__DOT__reorderBuffer__DOT__freeEntries) 
                                                     >> 1U)));
    Top__DOT__nextFreeSlots = (((IData)(Top__DOT__reorderBuffer__DOT__moreThanOne) 
                                << 1U) | (1U & (IData)(Top__DOT__reorderBuffer__DOT__freeEntries)));
    vlSelf->Top__DOT__rstBus2 = 0U;
    vlSelf->Top__DOT__rstBus1 = 0U;
    vlSelf->Top__DOT__rstBus3 = 0U;
    if (vlSelf->Top__DOT__redirect) {
        vlSelf->Top__DOT__freeTag1 = (0x1fU & ((IData)(1U) 
                                               + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT____VdfgTmp_h7cf4e22f__0)));
        if (((1U < (IData)(Top__DOT__reorderBuffer__DOT__flushCount)) 
             & ((0U != (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest2)) 
                & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest1) 
                   != (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest2))))) {
            vlSelf->Top__DOT__rstBus2 = (1U | (IData)(vlSelf->Top__DOT__rstBus2));
            vlSelf->Top__DOT__rstBus2 = ((1U & (IData)(vlSelf->Top__DOT__rstBus2)) 
                                         | (((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest2) 
                                             << 8U) 
                                            | (((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2) 
                                                << 3U) 
                                               | (((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found2)
                                                    ? 2U
                                                    : 3U) 
                                                  << 1U))));
        }
        if (((0U < (IData)(Top__DOT__reorderBuffer__DOT__flushCount)) 
             & (0U != (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest1)))) {
            vlSelf->Top__DOT__rstBus1 = (1U | (IData)(vlSelf->Top__DOT__rstBus1));
            vlSelf->Top__DOT__rstBus1 = ((7U & (IData)(vlSelf->Top__DOT__rstBus1)) 
                                         | (((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest1) 
                                             << 8U) 
                                            | ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minIndex1) 
                                               << 3U)));
            vlSelf->Top__DOT__rstBus1 = ((0x1ff9U & (IData)(vlSelf->Top__DOT__rstBus1)) 
                                         | (((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__found1)
                                              ? (((
                                                   ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minIndex1) 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(
                                                               (vlSelf->Top__DOT__resolvedInstruction1 
                                                                >> 1U)))) 
                                                   & (IData)(vlSelf->Top__DOT__resolvedInstruction1)) 
                                                  | (((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__minIndex1) 
                                                      == 
                                                      (0x1fU 
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
             & ((0U != (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest3)) 
                & (((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest1) 
                    != (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest3)) 
                   & ((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest2) 
                      != (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest3)))))) {
            vlSelf->Top__DOT__rstBus3 = (1U | (IData)(vlSelf->Top__DOT__rstBus3));
            vlSelf->Top__DOT__rstBus3 = ((1U & (IData)(vlSelf->Top__DOT__rstBus3)) 
                                         | (((IData)(vlSelf->Top__DOT__reorderBuffer__DOT__flushDest3) 
                                             << 8U) 
                                            | (((IData)(Top__DOT__reorderBuffer__DOT__minIndex3) 
                                                << 3U) 
                                               | (((IData)(Top__DOT__reorderBuffer__DOT__found3)
                                                    ? 2U
                                                    : 3U) 
                                                  << 1U))));
        }
    } else {
        vlSelf->Top__DOT__freeTag1 = (0x1fU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer));
    }
    vlSelf->Top__DOT__decodeIssue__DOT__reasonRobOneFree = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__reasonRobFull = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__block1 = 0U;
    vlSelf->Top__DOT__decodeIssue__DOT__block2 = 0U;
    if (vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid) {
        if ((1U != (IData)(Top__DOT__nextFreeSlots))) {
            if ((0U == (IData)(Top__DOT__nextFreeSlots))) {
                vlSelf->Top__DOT__decodeIssue__DOT__reasonRobFull = 1U;
            }
        }
        if (vlSelf->Top__DOT__decodeIssue__DOT__illegal1) {
            vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
        }
        if ((1U != (IData)(Top__DOT__nextFreeSlots))) {
            if ((0U == (IData)(Top__DOT__nextFreeSlots))) {
                vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
            }
        }
        if (vlSelf->Top__DOT__redirect) {
            vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
        }
        if (vlSelf->Top__DOT__destRegLoad1) {
            vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
        }
        if (((0U != (3U & ((vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                            << 1U) | (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                      >> 0x1fU)))) 
             & (~ (IData)(vlSelf->Top__DOT__memFreeSlot)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
        }
        if (vlSelf->Top__DOT__decodeIssue__DOT__illegal2) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__decodeIssue__DOT__illegal1) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((0U != (3U & ((vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[1U] 
                           << 1U) | (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                     >> 0x1fU))))) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
             == (IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2))) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (((1U == (3U & ((vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                            << 1U) | (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                      >> 0x1fU)))) 
             & (((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                 == (0x1fU & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                              >> 8U))) | ((IData)(vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1) 
                                          == (0x1fU 
                                              & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[2U] 
                                                 >> 0xdU)))))) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__decodeIssue__DOT__internalBadData) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if ((1U == (IData)(Top__DOT__nextFreeSlots))) {
            vlSelf->Top__DOT__decodeIssue__DOT__reasonRobOneFree = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        } else if ((0U == (IData)(Top__DOT__nextFreeSlots))) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__redirect) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__destRegLoad1) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__destRegLoad2) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (((0U != (3U & ((vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[1U] 
                            << 1U) | (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                      >> 0x1fU)))) 
             & (~ (IData)(vlSelf->Top__DOT__memFreeSlot)))) {
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
        if (vlSelf->Top__DOT__stall) {
            vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
            vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
        }
    } else {
        vlSelf->Top__DOT__decodeIssue__DOT__block1 = 1U;
        vlSelf->Top__DOT__decodeIssue__DOT__block2 = 1U;
    }
    vlSelf->Top__DOT__outputJal = 0U;
    vlSelf->Top__DOT__branchProgramCounter = 0U;
    if ((((IData)(((0U != (0xe000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U])) 
                   | (1U == (3U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                   >> 0x13U))))) & 
          (~ (IData)(vlSelf->Top__DOT__decodeIssue__DOT__illegal1))) 
         & (~ (IData)(vlSelf->Top__DOT__decodeIssue__DOT__block1)))) {
        vlSelf->Top__DOT__outputJal = (1U == (3U & 
                                              (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1[0U] 
                                               >> 0x13U)));
        vlSelf->Top__DOT__branchProgramCounter = vlSelf->Top__DOT__decodeIssue__DOT__PC1;
    } else if ((((((IData)(((0U != (0xe000000U & vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U])) 
                            | (1U == (3U & (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                            >> 0x13U))))) 
                   & (~ (IData)(vlSelf->Top__DOT__decodeIssue__DOT__illegal1))) 
                  & (~ (IData)(vlSelf->Top__DOT__decodeIssue__DOT__illegal2))) 
                 & (~ (IData)(vlSelf->Top__DOT__decodeIssue__DOT__block1))) 
                & (~ (IData)(vlSelf->Top__DOT__decodeIssue__DOT__block2)))) {
        vlSelf->Top__DOT__outputJal = (1U == (3U & 
                                              (vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2[0U] 
                                               >> 0x13U)));
        vlSelf->Top__DOT__branchProgramCounter = vlSelf->Top__DOT__decodeIssue__DOT__PC2;
    }
}

void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf);
void VTop___024root___nba_sequent__TOP__1(VTop___024root* vlSelf);
void VTop___024root___ico_comb__TOP__0(VTop___024root* vlSelf);

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__1(vlSelf);
        VTop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((5ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___ico_comb__TOP__0(vlSelf);
    }
}

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);
void VTop___024root___eval_act(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
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
bool VTop___024root___eval_phase__ico(VTop___024root* vlSelf);
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
            VL_FATAL_MT("Test/Subsystems/PipelineTest.sv", 6, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("Test/Subsystems/PipelineTest.sv", 6, "", "NBA region did not converge.");
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
                VL_FATAL_MT("Test/Subsystems/PipelineTest.sv", 6, "", "Active region did not converge.");
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
}
#endif  // VL_DEBUG
