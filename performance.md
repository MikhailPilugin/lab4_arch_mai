# Тестирование времени отклика и пропускной способности

<details>
<summary>1 поток, 1 соединение</summary>

### С кешем
<pre>stud@ubuntu:~/lab4_arch_mai$ wrk -d 10 -t 1 -c 1 --latency -s ./test/get_cache.lua http://localhost:8080/
Running 10s test @ http://localhost:8080/
  1 threads and 1 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     3.71ms  810.96us  24.01ms   89.15%
    Req/Sec   270.36     19.81   297.00     81.00%
  Latency Distribution
     50%    3.65ms
     75%    3.96ms
     90%    4.34ms
     99%    5.63ms
  2704 requests in 10.04s, 763.14KB read
  Non-2xx or 3xx responses: 2704
Requests/sec:    269.28
Transfer/sec:     76.00KB
</pre>

### Без кеша
<pre>stud@ubuntu:~/lab4_arch_mai$ wrk -d 10 -t 1 -c 1 --latency -s ./test/get_no_cache.lua http://localhost:8080/
Running 10s test @ http://localhost:8080/
  1 threads and 1 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     2.37ms  754.57us  14.66ms   90.09%
    Req/Sec   426.44     34.50   530.00     83.00%
  Latency Distribution
     50%    2.23ms
     75%    2.53ms
     90%    2.95ms
     99%    4.81ms
  4262 requests in 10.04s, 1.17MB read
  Non-2xx or 3xx responses: 4262
Requests/sec:    424.62
Transfer/sec:    119.84KB
</pre>
</details>

<details>
<summary>2 потока, 2 соединения</summary>

### С кешем
<pre>stud@ubuntu:~/lab4_arch_mai$ wrk -d 10 -t 2 -c 2 --latency -s ./test/get_cache.lua http://localhost:8080/
Running 10s test @ http://localhost:8080/
  2 threads and 2 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     7.00ms    2.49ms  47.63ms   89.39%
    Req/Sec   144.97     15.35   202.00     85.00%
  Latency Distribution
     50%    6.80ms
     75%    7.56ms
     90%    8.65ms
     99%   16.52ms
  2904 requests in 10.06s, 811.08KB read
  Non-2xx or 3xx responses: 2904
Requests/sec:    288.80
Transfer/sec:     80.66KB
</pre>

### Без кеша
<pre>stud@ubuntu:~/lab4_arch_mai$ wrk -d 10 -t 2 -c 2 --latency -s ./test/get_no_cache.lua http://localhost:8080/
Running 10s test @ http://localhost:8080/
  2 threads and 2 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     4.88ms    1.09ms  13.53ms   76.04%
    Req/Sec   205.06     15.69   230.00     78.00%
  Latency Distribution
     50%    4.72ms
     75%    5.43ms
     90%    6.23ms
     99%    8.20ms
  4106 requests in 10.05s, 1.14MB read
  Non-2xx or 3xx responses: 4106
Requests/sec:    408.37
Transfer/sec:    115.66KB
</pre>
</details>

<details>
<summary>5 потоков, 5 соединений</summary>

### С кешем
<pre>stud@ubuntu:~/lab4_arch_mai$ wrk -d 10 -t 5 -c 5 --latency -s ./test/get_cache.lua http://localhost:8080/
Running 10s test @ http://localhost:8080/
  5 threads and 5 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    17.58ms    3.42ms  38.52ms   77.42%
    Req/Sec    56.87      7.35    70.00     76.40%
  Latency Distribution
     50%   17.08ms
     75%   19.04ms
     90%   21.67ms
     99%   29.05ms
  2858 requests in 10.08s, 808.38KB read
  Non-2xx or 3xx responses: 2858
Requests/sec:    283.54
Transfer/sec:     80.20KB
</pre>

### Без кеша
<pre>stud@ubuntu:~/lab4_arch_mai$ wrk -d 10 -t 5 -c 5 --latency -s ./test/get_no_cache.lua http://localhost:8080/
Running 10s test @ http://localhost:8080/
  5 threads and 5 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    12.13ms    3.28ms  63.53ms   82.92%
    Req/Sec    83.00     10.00   101.00     82.40%
  Latency Distribution
     50%   11.68ms
     75%   13.19ms
     90%   15.26ms
     99%   21.76ms
  4175 requests in 10.09s, 1.15MB read
  Non-2xx or 3xx responses: 4175
Requests/sec:    413.65
Transfer/sec:    116.53KB
</pre>
</details>

<details>
<summary>10 потоков, 10 соединений</summary>

### С кешем
<pre>stud@ubuntu:~/lab4_arch_mai$ wrk -d 10 -t 10 -c 10 --latency -s ./test/get_cache.lua http://localhost:8080/
Running 10s test @ http://localhost:8080/
  10 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    38.50ms   16.82ms 277.44ms   89.58%
    Req/Sec    26.67      6.69    70.00     81.41%
  Latency Distribution
     50%   35.48ms
     75%   40.29ms
     90%   51.14ms
     99%  102.12ms
  2681 requests in 10.09s, 756.83KB read
  Non-2xx or 3xx responses: 2681
Requests/sec:    265.68
Transfer/sec:     75.00KB
</pre>

### Без кеша
<pre>stud@ubuntu:~/lab4_arch_mai$ wrk -d 10 -t 10 -c 10 --latency -s ./test/get_no_cache.lua http://localhost:8080/
Running 10s test @ http://localhost:8080/
  10 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    25.69ms    7.07ms  72.35ms   79.32%
    Req/Sec    38.87      8.37   120.00     53.07%
  Latency Distribution
     50%   24.21ms
     75%   28.00ms
     90%   35.54ms
     99%   49.22ms
  3906 requests in 10.10s, 1.07MB read
  Non-2xx or 3xx responses: 3906
Requests/sec:    386.83
Transfer/sec:    108.98KB
</pre>
</details>