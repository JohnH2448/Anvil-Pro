import Configuration::*;
import Payloads::*;
import Enumerations::*;

// mini single req store buffer with forwarding so you dont need to wait for ack
// back. fairly simple, just hold recent outgoing store and forward
// to in flight loads. This is past ROB and lets stores commit fast.
// basically stall mem queue but forward to loads if needed. must keep
// bus live to maintain transaction for ack.
// actually with inter queue forwarding this may not be necissary.
// unless theres a case im missing, rob doesnt need ack 

// to start, rob will wait for ack. optimize later with above
// StoreACK to ROB must be broadcast in this domain by Queue until next edge

// definitely do a store buffer that bypasses issue restrictions. It can forward to OS
// Maybe 16ish entries from most recent stores. configurable size?