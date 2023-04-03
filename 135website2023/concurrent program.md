#terminology

## Definition
A program that has one, or more, CPUs, and so could be doing two different things at the same time.

Debugging concurrent programs is generally much more difficult than debugging non-current programs (i.e. programs with a single thread of control). [[race condition|Race conditions]] are a major source of bugs in concurrent programs.

Note that it is possible for a single-CPU program to be concurrent: it is possible to simulate concurrency.

## Example
Web servers are usually implemented as concurrent programs. A popular website might have hundreds of people accessing pages from it at the same time, and so web servers typically use one thread of control per user.
