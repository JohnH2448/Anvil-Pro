// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop___024unit.h"

void VTop___024unit___ctor_var_reset(VTop___024unit* vlSelf);

VTop___024unit::VTop___024unit(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop___024unit___ctor_var_reset(this);
}

void VTop___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VTop___024unit::~VTop___024unit() {
}
