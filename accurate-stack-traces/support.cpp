
void debug_trap() {
  asm("int3;");
}
void extern_function() {}

bool unknown_bool(bool b) { return b; }
int unknown_int(int i) { return i; }
