# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` and executed on the same machine: an Intel Core Ultra 7 255H running Ubuntu under WSL2 (Linux 6.18.58.1-microsoft-standard-WSL2, x86_64). Each program was run three consecutive times without changing the environment between runs. Time was measured inside the programs using `clock()` from `<time.h>`, converted to seconds by dividing by `CLOCKS_PER_SEC`. `clock()` measures processor time used by the program, not wall-clock time.

For the instrumentation lab, each phase was timed around its single function call. The end timestamp of one phase is the start timestamp of the next, so no time is lost between phases. `TOTAL` was measured with its own start and end points around all three phases, and every `printf` call happens after measurement, so printing is never included in the timings.

## Observed Performance Differences

The baseline loop (100,000,000 iterations) measured 0.084995 s, 0.102491 s and 0.159047 s, an average of about 0.1155 s. The slowest run took almost twice as long as the fastest, even though the code and input were identical. This shows that a single run is not reliable evidence.

In the algorithm comparison, the naive implementation averaged 0.854580 s while the single-pass implementation averaged 0.000031 s. The naive version was about 27,867 times slower. This matches the amount of work each one does: the naive version checks an element `1 + 2 + ... + 50,000 = 1,250,025,000` times, while the single pass checks 50,000 elements, a ratio of about 25,000. The measured ratio is close to that prediction: the difference comes from the algorithm (quadratic versus linear), not the language.

In the instrumentation lab, the three runs gave a `TOTAL` of 0.000295 s, 0.000280 s and 0.000275 s. On average, `BUILD_DATA` took about 0.000143 s (around 51% of the total), `PROCESS` about 0.000093 s, and `REDUCE` about 0.000046 s. The sum of the three phases (about 0.000282 s) is very close to the average `TOTAL` (about 0.000283 s), which confirms the boundaries were placed consistently and `TOTAL` was always greater than or equal to each phase.

## Relation Between Runtime and Energy Consumption

This project did not measure power in watts. Runtime is used as a proxy: while a program runs, the CPU stays active and consumes energy. Using the measured numbers, the naive algorithm kept the CPU busy for about 0.85 s to do work that the single-pass algorithm finished in about 0.00003 s. At scale, the quadratic version would multiply CPU time, and therefore energy use, by thousands.

## Limitations of the Experiment

- Only three runs were recorded per program, and the baseline already varied by almost a factor of two between runs, so averages over three runs are rough.
- The tests ran inside WSL2, where Windows and other background processes share the same CPU, which can explain part of the variability.
- The single-pass and instrumentation timings are in the tens to hundreds of microseconds, close to the resolution of `clock()`, so their relative error is large.
- The two algorithms in the comparison do not return the same result (naive returned 625,025,000 and single-pass returned 25,000), because the naive version recounts the prefix of the array for every `i`. They are not interchangeable implementations.
- Runtime is only an indirect proxy for energy; no power measurements were taken.

## Practical Engineering Takeaway

The biggest efficiency gain in these measurements came from the choice of algorithm, not from small code tweaks: removing a nested loop changed runtime by a factor of about 27,867. Before optimizing, an engineer should measure several runs on the same machine, check that the implementations produce the same output, and look first at the algorithmic complexity, where most CPU time and energy is saved.
