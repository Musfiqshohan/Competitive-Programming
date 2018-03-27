As someone who frequently writes top-down (recursive) dynamic programming solutions let me tell you that you can almost always solve dynamic programming problems this way.  The top-down and iterative approaches each have the following advantages:

Top-down

Many (including myself) find it easier to write code this way.
No need to consider which states depend on which; recursion will take care of this (though do make sure that your 'recurrence' is acyclic).  This is pretty handy when the dependencies are complicated like in a tree DP problem.
You won't do work for unreachable states.  Sometimes this can offer a significant speedup.
Extra information, that's not needed to uniquely identify a state, is often easier to track.

Iterative (bottom-up)

Many find it easier to write code this way.
Iterative code is usually a bit faster than recursive code.
Iterative code has lower memory consumption when the max dependency depth is large.  It also isn't limited by the stack size.
Allows for intermediate data structures to speed up recurrence calculation.  For example you can solve longest increasing subsequence with dynamic programming and a tree data-structure in O(N log N) where there is no equivalent O(N log N) top-down approach.
With the previous bullet; Expressing the problem in the bottom-up fashion often reveals data patterns that suggest what data-structures and computation transformations could speed it up.
