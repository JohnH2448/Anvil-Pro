// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf);
void VTop___024root___ico_comb__TOP__0(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___ico_comb__TOP__0(vlSelf);
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
    if ((2ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 1 is active: @([hybrid] Top.taken)\n");
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
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] Top.taken)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge clock)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge clock)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] Top.taken)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge clock)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge clock)\n");
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
    vlSelf->tohost = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__resolvedInstruction1 = VL_RAND_RESET_Q(43);
    vlSelf->Top__DOT__resolvedInstruction2 = VL_RAND_RESET_Q(43);
    vlSelf->Top__DOT__freeTag1 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__rstBus1 = VL_RAND_RESET_I(13);
    vlSelf->Top__DOT__rstBus2 = VL_RAND_RESET_I(13);
    vlSelf->Top__DOT__rstBus3 = VL_RAND_RESET_I(13);
    vlSelf->Top__DOT__upperSource1Status = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__upperSource2Status = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__lowerSource1Status = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__lowerSource2Status = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__oldLowerStatus = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__oldUpperStatus = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__destRegLoad1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__destRegLoad2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__instructionConsumed1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__instructionConsumed2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__requestPC1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__requestPC2 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(114, vlSelf->Top__DOT__payload1);
    VL_RAND_RESET_W(109, vlSelf->Top__DOT__payload2);
    vlSelf->Top__DOT__instructionPacket1 = VL_RAND_RESET_Q(44);
    vlSelf->Top__DOT__instructionPacket2 = VL_RAND_RESET_Q(44);
    vlSelf->Top__DOT__precalcAddress = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__branchProgramCounter = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__outputJal = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__taken = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__bpUpdateValid1 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(154, vlSelf->Top__DOT__exPayload1);
    VL_RAND_RESET_W(151, vlSelf->Top__DOT__exPayload2);
    vlSelf->Top__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__resultPayload1 = VL_RAND_RESET_Q(43);
    vlSelf->Top__DOT__resultPayload2 = VL_RAND_RESET_Q(43);
    VL_RAND_RESET_W(79, vlSelf->Top__DOT__memPayload);
    vlSelf->Top__DOT__redirect = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__redirectVector = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__mispredict1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__instruction1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__instruction2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__programCounter = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__completedMemory = VL_RAND_RESET_Q(43);
    VL_RAND_RESET_W(71, vlSelf->Top__DOT__memBusOut);
    vlSelf->Top__DOT__memFreeSlot = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(69, vlSelf->Top__DOT__storeBus1);
    vlSelf->Top__DOT__finalOutputData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__outputValid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__lowFetchData);
    VL_RAND_RESET_W(128, vlSelf->Top__DOT__highFetchData);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_RAND_RESET_W(83, vlSelf->Top__DOT__memoryQueue__DOT__queueEntry[__Vi0]);
    }
    vlSelf->Top__DOT__memoryQueue__DOT__tailPointer = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__memoryQueue__DOT__byteSelectTransform = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__memoryQueue__DOT__unnamedblk3__DOT__unnamedblk5__DOT__index = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 20; ++__Vi0) {
        VL_RAND_RESET_W(69, vlSelf->Top__DOT__storeBuffer__DOT__shiftEntries[__Vi0]);
    }
    VL_RAND_RESET_W(69, vlSelf->Top__DOT__storeBuffer__DOT____Vlvbound_ha6fc8e3e__0);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->Top__DOT__placeholderDMEM__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__placeholderDMEM__DOT__memBusInRegister = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__placeholderDMEM__DOT__requestPending = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__placeholderDMEM__DOT__latchedAddress = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__placeholderDMEM__DOT__latchedStoreData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__placeholderDMEM__DOT__latchedWriteEnable = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__placeholderDMEM__DOT__latchedByteSelect = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__placeholderDMEM__DOT__delayCounter = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__placeholderDMEM__DOT__validRequest = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__placeholderDMEM__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->Top__DOT__placeholderDMEM__DOT__unnamedblk2__DOT__wordIndex = VL_RAND_RESET_I(10);
    vlSelf->Top__DOT__placeholderDMEM__DOT__unnamedblk2__DOT__nextLoadData = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__reorderBuffer__DOT__retireCount = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__reorderBuffer__DOT__headPointer = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__reorderBuffer__DOT__tailPointer = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__reorderBuffer__DOT__redirectPointer = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__reorderBuffer__DOT__nextHeadPointer = VL_RAND_RESET_I(6);
    vlSelf->Top__DOT__reorderBuffer__DOT__nextTailPointer = VL_RAND_RESET_I(6);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        VL_RAND_RESET_W(76, vlSelf->Top__DOT__reorderBuffer__DOT__reorderBuffer[__Vi0]);
    }
    vlSelf->Top__DOT__reorderBuffer__DOT__flushDest1 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__flushDest2 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__flushDest3 = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__reorderBuffer__DOT__sortGrid[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 3; ++__Vi1) {
            vlSelf->Top__DOT__reorderBuffer__DOT__maskGrid[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    vlSelf->Top__DOT__reorderBuffer__DOT__minIndex1 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__minIndex2 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__minValue2 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__reorderBuffer__DOT__found1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__reorderBuffer__DOT__found2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__reorderBuffer__DOT____VdfgTmp_h7cf4e22f__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__registerStatusTable__DOT__registerStatusTable[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__registerFile__DOT__registerFile[__Vi0] = VL_RAND_RESET_I(32);
    }
    VL_RAND_RESET_W(154, vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate1);
    VL_RAND_RESET_W(151, vlSelf->Top__DOT__operandSelect__DOT__exPayloadCandidate2);
    vlSelf->Top__DOT__operandSelect__DOT__upperSource1Status = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__operandSelect__DOT__upperSource2Status = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__operandSelect__DOT__lowerSource1Status = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__operandSelect__DOT__lowerSource2Status = VL_RAND_RESET_I(8);
    vlSelf->Top__DOT__execute__DOT__result1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__result2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute__DOT__redirect1 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__execute__DOT__redirect2 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__execute__DOT__illegal2 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->Top__DOT__branchPredictor__DOT__counterTable[__Vi0] = VL_RAND_RESET_I(2);
    }
    vlSelf->Top__DOT__decodeIssue__DOT__illegal2 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(114, vlSelf->Top__DOT__decodeIssue__DOT__tempPayload2);
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister2 = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__decodeIssue__DOT__illegal1 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(114, vlSelf->Top__DOT__decodeIssue__DOT__tempPayload1);
    vlSelf->Top__DOT__decodeIssue__DOT__destinationRegister1 = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(114, vlSelf->Top__DOT__decodeIssue__DOT__finalUpperPayload);
    VL_RAND_RESET_W(109, vlSelf->Top__DOT__decodeIssue__DOT__finalLowerPayload);
    vlSelf->Top__DOT__decodeIssue__DOT__IR1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__IR2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__PC1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__PC2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__instructionsValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__postRedirectCounter = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__internalBadData = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__decodeIssue__DOT__slot0TakenHelper = VL_RAND_RESET_I(1);
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
    vlSelf->Top__DOT__decodeIssue__DOT__target1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__target2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__decodeIssue__DOT__staleVector1 = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__decodeIssue__DOT__staleVector2 = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__walkingWindow__DOT__lastLowWindow = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__walkingWindow__DOT__lastHighWindow = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->Top__DOT__instructionMemory__DOT__memory[__Vi0]);
    }
    vlSelf->Top__DOT__instructionMemory__DOT__redirectAddress = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__taken__0 = VL_RAND_RESET_I(1);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__taken__1 = VL_RAND_RESET_I(1);
    vlSelf->__VicoDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__Top__DOT__taken__2 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
