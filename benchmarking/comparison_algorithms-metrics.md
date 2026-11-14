# Algorithmic Efficiency Comparison

Compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long comparison_algorithms.c -o comparison_algorithms`

Results returned: Naive = 625025000, Single-pass = 25000

## Execution times

| Run | Naive (s) | Single-pass (s) |
|-----|-----------|-----------------|
| 1 | 0.930618 | 0.000019 |
| 2 | 0.794913 | 0.000051 |
| 3 | 0.838209 | 0.000022 |

## Averages and relative difference

- Naive average: 0.854580 seconds
- Single-pass average: 0.000031 seconds
- Relative difference: Naive is ~27867 times slower than Single-pass

## Raw output

```
Naive algorithm result: 625025000
Naive algorithm time: 0.930618 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000019 seconds
Naive algorithm result: 625025000
Naive algorithm time: 0.794913 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000051 seconds
Naive algorithm result: 625025000
Naive algorithm time: 0.838209 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000022 seconds
```
