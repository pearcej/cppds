Self-check
----------

.. mchoice:: laws
   :multiple_answers:
   :answer_a: It must progress from the base case
   :answer_b: It must move towards the base case
   :answer_c: It must have a base case
   :answer_d: It must call itself
   :correct: b,c,d
   :feedback_a: If it starts at the base case, then when would it stop?
   :feedback_b: Correct. The base case is your endpoint.
   :feedback_c: Correct. The base case is essential if you want a stopping point
   :feedback_d: Correct. If it doesn't call itself then it won't repeat

   What are the three laws of recursion for an algorithm? (choose all that are correct)

.. dragndrop:: whenToRecurse
  :feedback: Consider what would make you stop the process for each one.
  :match_1: Counting the number of items in a list|||Iteration
  :match_2: Going through an entire tree|||Recursion

  Which implementation would be ideal for each problem.

.. mchoice:: recursionefficiencyq
   :answer_a: True
   :answer_b: False
   :correct: a
   :feedback_a: Correct! Sometimes simple problems only need simple solutions, like a loop
   :feedback_b: Incorrect. Recursion is not always the ideal solution. 
   
    Sometimes recursion can be more computationally expensive than an alternative, True or False?
