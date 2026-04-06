// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("Register File\nx00=%08x  x01=%08x  x02=%08x  x03=%08x\nx04=%08x  x05=%08x  x06=%08x  x07=%08x\nx08=%08x  x09=%08x  x10=%08x  x11=%08x\nx12=%08x  x13=%08x  x14=%08x  x15=%08x\nx16=%08x  x17=%08x  x18=%08x  x19=%08x\nx20=%08x  x21=%08x  x22=%08x  x23=%08x\nx24=%08x  x25=%08x  x26=%08x  x27=%08x\nx28=%08x  x29=%08x  x30=%08x  x31=%08x\n\n",
                  32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [1U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [2U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [3U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [4U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [5U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [6U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [7U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [8U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [9U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0xaU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0xbU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0xcU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0xdU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0xeU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0xfU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x10U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x11U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x12U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x13U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x14U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x15U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x16U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x17U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x18U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x19U],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x1aU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x1bU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x1cU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x1dU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x1eU],32,vlSelf->Top__DOT__registerFile__DOT__registerFile
                  [0x1fU]);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("Memory Queue\ntail=%0# completed=%0b ack=%0b\n",
                  4,vlSelf->Top__DOT__memoryQueue__DOT__tailPointer,
                  1,(1U & (IData)(vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister)),
                  1,(1U & (IData)(vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister)));
        if (VL_UNLIKELY((0U == (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)))) {
            VL_WRITEF("empty\n");
        } else {
            if (VL_UNLIKELY((0U < (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)))) {
                VL_WRITEF("[0] op=%0# addr=%08x data=%08x width=%02b sign=%0b tag=%0# rd=x%0#\n",
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [0U][0U] >> 0xcU)),
                          32,((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [0U][2U] << 0x12U) | 
                              (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [0U][1U] >> 0xeU)),32,
                          ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                            [0U][1U] << 0x12U) | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [0U][0U] 
                                                  >> 0xeU)),
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [0U][0U] >> 0xaU)),
                          1,(1U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [0U][0U] >> 9U)),
                          4,(0xfU & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [0U][0U]),5,(0x1fU & (
                                                   vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                   [0U][0U] 
                                                   >> 4U)));
            }
            if (VL_UNLIKELY((1U < (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)))) {
                VL_WRITEF("[1] op=%0# addr=%08x data=%08x width=%02b sign=%0b tag=%0# rd=x%0#\n",
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [1U][0U] >> 0xcU)),
                          32,((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [1U][2U] << 0x12U) | 
                              (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [1U][1U] >> 0xeU)),32,
                          ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                            [1U][1U] << 0x12U) | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [1U][0U] 
                                                  >> 0xeU)),
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [1U][0U] >> 0xaU)),
                          1,(1U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [1U][0U] >> 9U)),
                          4,(0xfU & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [1U][0U]),5,(0x1fU & (
                                                   vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                   [1U][0U] 
                                                   >> 4U)));
            }
            if (VL_UNLIKELY((2U < (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)))) {
                VL_WRITEF("[2] op=%0# addr=%08x data=%08x width=%02b sign=%0b tag=%0# rd=x%0#\n",
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [2U][0U] >> 0xcU)),
                          32,((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [2U][2U] << 0x12U) | 
                              (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [2U][1U] >> 0xeU)),32,
                          ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                            [2U][1U] << 0x12U) | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [2U][0U] 
                                                  >> 0xeU)),
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [2U][0U] >> 0xaU)),
                          1,(1U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [2U][0U] >> 9U)),
                          4,(0xfU & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [2U][0U]),5,(0x1fU & (
                                                   vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                   [2U][0U] 
                                                   >> 4U)));
            }
            if (VL_UNLIKELY((3U < (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)))) {
                VL_WRITEF("[3] op=%0# addr=%08x data=%08x width=%02b sign=%0b tag=%0# rd=x%0#\n",
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [3U][0U] >> 0xcU)),
                          32,((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [3U][2U] << 0x12U) | 
                              (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [3U][1U] >> 0xeU)),32,
                          ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                            [3U][1U] << 0x12U) | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [3U][0U] 
                                                  >> 0xeU)),
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [3U][0U] >> 0xaU)),
                          1,(1U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [3U][0U] >> 9U)),
                          4,(0xfU & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [3U][0U]),5,(0x1fU & (
                                                   vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                   [3U][0U] 
                                                   >> 4U)));
            }
            if (VL_UNLIKELY((4U < (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)))) {
                VL_WRITEF("[4] op=%0# addr=%08x data=%08x width=%02b sign=%0b tag=%0# rd=x%0#\n",
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [4U][0U] >> 0xcU)),
                          32,((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [4U][2U] << 0x12U) | 
                              (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [4U][1U] >> 0xeU)),32,
                          ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                            [4U][1U] << 0x12U) | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [4U][0U] 
                                                  >> 0xeU)),
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [4U][0U] >> 0xaU)),
                          1,(1U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [4U][0U] >> 9U)),
                          4,(0xfU & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [4U][0U]),5,(0x1fU & (
                                                   vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                   [4U][0U] 
                                                   >> 4U)));
            }
            if (VL_UNLIKELY((5U < (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)))) {
                VL_WRITEF("[5] op=%0# addr=%08x data=%08x width=%02b sign=%0b tag=%0# rd=x%0#\n",
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [5U][0U] >> 0xcU)),
                          32,((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [5U][2U] << 0x12U) | 
                              (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [5U][1U] >> 0xeU)),32,
                          ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                            [5U][1U] << 0x12U) | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [5U][0U] 
                                                  >> 0xeU)),
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [5U][0U] >> 0xaU)),
                          1,(1U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [5U][0U] >> 9U)),
                          4,(0xfU & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [5U][0U]),5,(0x1fU & (
                                                   vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                   [5U][0U] 
                                                   >> 4U)));
            }
            if (VL_UNLIKELY((6U < (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)))) {
                VL_WRITEF("[6] op=%0# addr=%08x data=%08x width=%02b sign=%0b tag=%0# rd=x%0#\n",
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [6U][0U] >> 0xcU)),
                          32,((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [6U][2U] << 0x12U) | 
                              (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [6U][1U] >> 0xeU)),32,
                          ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                            [6U][1U] << 0x12U) | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [6U][0U] 
                                                  >> 0xeU)),
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [6U][0U] >> 0xaU)),
                          1,(1U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [6U][0U] >> 9U)),
                          4,(0xfU & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [6U][0U]),5,(0x1fU & (
                                                   vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                   [6U][0U] 
                                                   >> 4U)));
            }
            if (VL_UNLIKELY((7U < (IData)(vlSelf->Top__DOT__memoryQueue__DOT__tailPointer)))) {
                VL_WRITEF("[7] op=%0# addr=%08x data=%08x width=%02b sign=%0b tag=%0# rd=x%0#\n",
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [7U][0U] >> 0xcU)),
                          32,((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [7U][2U] << 0x12U) | 
                              (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                               [7U][1U] >> 0xeU)),32,
                          ((vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                            [7U][1U] << 0x12U) | (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                  [7U][0U] 
                                                  >> 0xeU)),
                          2,(3U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [7U][0U] >> 0xaU)),
                          1,(1U & (vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                   [7U][0U] >> 9U)),
                          4,(0xfU & vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                             [7U][0U]),5,(0x1fU & (
                                                   vlSelf->Top__DOT__memoryQueue__DOT__queueEntry
                                                   [7U][0U] 
                                                   >> 4U)));
            }
        }
    }
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if ((0U == (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries))) {
            VL_WRITEF("\nReorder Buffer\nhead=%0# tail=%0# entries=%0# free=%0# empty\n\n",
                      5,vlSelf->Top__DOT__reorderBuffer__DOT__headPointer,
                      5,(IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer),
                      5,vlSelf->Top__DOT__reorderBuffer__DOT__entries,
                      5,(IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeEntries));
        } else {
            VL_WRITEF("\nReorder Buffer\nhead=%0# tail=%0# entries=%0# free=%0#\n",
                      5,vlSelf->Top__DOT__reorderBuffer__DOT__headPointer,
                      5,(IData)(vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer),
                      5,vlSelf->Top__DOT__reorderBuffer__DOT__entries,
                      5,(IData)(vlSelf->Top__DOT__reorderBuffer__DOT__freeEntries));
            if (VL_UNLIKELY((0U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((1U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((2U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(2U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((3U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(3U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((4U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(4U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((5U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(5U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((6U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(6U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((7U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(7U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((8U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(8U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((9U < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(9U) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((0xaU < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(0xaU) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((0xbU < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(0xbU) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((0xcU < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(0xcU) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((0xdU < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(0xdU) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((0xeU < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(0xeU) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
            if (VL_UNLIKELY((0xfU < (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__entries)))) {
                vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex 
                    = (0xfU & ((IData)(0xfU) + (IData)(vlSelf->Top__DOT__reorderBuffer__DOT__headPointer)));
                VL_WRITEF("[%0#] pc=%08x rd=x%0# tag=%0# ready=%0b stdOp=%0b data=%08x\n",
                          4,vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex,
                          32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                               [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][2U] 
                               << 0x15U) | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                            [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                            >> 0xbU)),
                          5,(0x1fU & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                      [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                      >> 6U)),4,(0xfU 
                                                 & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                    [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                    >> 2U)),
                          1,(1U & vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                             [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U]),
                          1,(1U & (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                   [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                   >> 1U)),32,((vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][1U] 
                                                << 0x15U) 
                                               | (vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer
                                                  [vlSelf->Top__DOT__reorderBuffer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__queueIndex][0U] 
                                                  >> 0xbU)));
            }
        }
    }
}

void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf);

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);
void VTop___024root___eval_act(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
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
