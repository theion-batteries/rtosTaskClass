# Esp cpp capabilities

this repo proofs that esp32 is capable of all cpp features and this makes the code portable and testable.
here the simulation: https://wokwi.com/projects/332077916033647188

# test time with static and runtime polymorphism
with output stream / without output: nanoseconds

* virtual: 

raw_ptr: 2253824000/ 127000

unqiue_ptr: 2253831000

shared_ptr: 2253872000

* crtp: 

raw_ptr: 2253797000 / 24000

unqiue_ptr: 2253866000

shared_ptr: 2253791000

static is 127/24 = 5 time fatser upon call
conclusion: static vs runtime polymorphism will only make difference upon dispatch, no relevant gain when runtime is looping