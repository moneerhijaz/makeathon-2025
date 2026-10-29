# ECLAIR Makeathon 2025 · historical firmware

ESP32/Arduino experiments for a four-IR-sensor, two-motor line-following robot. The [portfolio account](https://hijaz.dev/experience/eclair-makeathon-2025/) records Moneer Hijaz as Lead Programmer on the first-place team. This repository does not establish which sketch ran in the competition.

## What is here

`sketch_mar9a/IR_Tracker.ino` reads digital sensors on pins 19, 34, 35, and 39 and selects forward, turn, or stop commands. Motor direction pins are 26/25 and 33/32, with PWM on 27 and 14. It uses fixed comparisons, not a PID loop.

`sketch_mar9a/sketch_mar9a.ino` is a more experimental alternative. Both files define `setup()` and `loop()`, so Arduino's normal same-folder concatenation cannot build them together. The latter also redeclares a parameter in `TurnLeft`, refers to an undefined `ir3_value` in `hardRight`, and contains turn loops whose sensor values are not refreshed.

## Reproduction boundary

Do not upload the directory as a working combined sketch. To inspect the simpler variant, copy **only** `IR_Tracker.ino` into a new `IR_Tracker/` sketch directory and select the actual ESP32 board and compatible Arduino core. No board/core version is pinned, so compilation and hardware operation are not verified here.

Lift wheels, use power appropriate to the motor driver, and keep an independent cutoff available. The code has no communication-loss stop or physical emergency-stop interface. Pin mappings are source observations, not a verified wiring specification.

The original experiments are preserved unchanged. Next useful work is to identify the competition revision and board/toolchain before repairing or consolidating them. No license is present; obtain author/team permission before redistribution. Electrical/mechanical teammate credits remain to be supplied.
