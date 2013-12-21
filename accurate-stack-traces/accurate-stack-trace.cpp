
/// These helper routines are defined in a separate file to avoid any 
/// possibility of inlining or insepction by the compiler
extern void debug_trap();
extern void extern_function();
extern bool unknown_bool(bool b);
extern int unknown_int(int i);

void a() {
  debug_trap();
  extern_function();
}
void b() {
  a();
  extern_function();
}
void c() {
  a();
  extern_function();
}

__attribute__((noinline))
void inlining_path() {
  b();
  c();
  extern_function();
}

__attribute__((noinline))
void block_combine(bool condition) {
  if( condition ) {
    a();
  } else {
    b();
  }
  extern_function();
}
__attribute__((noinline))
void tail_call_opt(int i) {
  if(i <= 0) {
    debug_trap();
    extern_function();
  }
  else tail_call_opt(i-1);
}

void sibling() { 
  debug_trap(); 
  extern_function();
}
__attribute__((noinline))
void sibling_call_opt() {
  sibling(); //In tail call position
}

int main() {
  inlining_path();
  block_combine( unknown_bool(true) );
  tail_call_opt( unknown_int(5) );
  sibling_call_opt();
  extern_function();
}
