import Configuration::*;
import Payloads::*;
import Enumerations::*;

// mini single req store buffer with forwarding so you dont need to wait for ack
// back. fairly simple, just hold recent outgoing store and forward
// to in flight loads. This is past ROB and lets stores commit fast.
// basically stall mem queue but forward to loads if needed. must keep
// bus live to maintain transaction for ack.
// actually with inter queue forwarding this may not be necissary.
// unless theres a case im missing, rob doesnt need ack to commit stores
// so long as the bus transaction holds until ack. 