Self Check
-----------

.. mchoice:: bigOefficiency
    :answer_a: 10000(n<sup>3</sup> + n<sup>2</sup>)
    :answer_b: 45n<sup>3</sup> + 1710n<sup>2</sup> + 16n + 5
    :answer_c: (n<sup>3</sup> + n) (n<sup>2</sup> + 1) 
    :answer_d: A and B would be equally efficient/inefficient 
    :correct: c
    :feedback_a: Incorrect, even though n<sup>3</sup> is the most significant part for all of these formulas, the way it interacts with the rest of the equation is also important to note.
    :feedback_b: Incorrect, even though n<sup>3</sup> is the most significant part for all of these formulas, the way it interacts with the rest of the equation is also important to note.
    :feedback_c: Correct!
    :feedback_d: Look closer, the efficiencies would be different

    Which of the following algorithms has the least efficient big O complexity?

.. dragndrop:: growth
    :feedback: Compare the functions at different values to see how they compare
    :match_1: 2<sup>n</sup>|||1st
    :match_2: n<sup>2</sup>|||2nd
    :match_3: nlogn|||3rd
    :match_4: logn|||4th

    Drag the order of growth rates to their rankings from lowest to highest (the slowest i.e. the highest growth rate should be #1)

.. mchoice:: resources
   :multiple_answers:
   :answer_a: language constraints
   :answer_b: Space
   :answer_c: Time
   :answer_d: Energy
   :correct: b,c
   :feedback_a: No, we do not consider the restraints of a language when thinking about how efficient an algorithm is.
   :feedback_b: Yes, we consider how much space we need to solve a problem.
   :feedback_c: Yes, we consider how much time it takes to solve a problem
   :feedback_d: No, we do not consider how much energy it takes at this point.

   When considering computer resources, what factors do we have in mind? Select all that apply.

.. mchoice:: bigO
  :answer_a: the space it takes
  :answer_b: the time it takes
  :answer_c: the number of steps
  :answer_d: the readability of the code
  :correct: c
  :feedback_a: This can be dependent of the programming language
  :feedback_b: This can be dependent on the machine, programming language, and other factors
  :feedback_c: Yes, when quantifying the time it takes to execute an algorithm we base it on the number of steps it takes to solve the problem, not the time it takes
  :feedback_d: No, a very efficient algorithm can be programmed efficiently in C++ without any extra spaces making it unreadable, however the solution would still be efficient.

  When considering the Big O of an algorithm, what do we use to quantify our description of an algorithm.

