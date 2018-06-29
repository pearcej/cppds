
Operator Overloading
--------------------

Defining a new meaning for an already existing operator (such as the arithmetic operators plus "+" or times "*") is called overloading the operator. Such overloading is easy to do in C++ with the correctly structured declaration, using the following prototype:
type operator symbol(s)( parameters );

Operators such as (+, -, \*, /, %, ==, <, >, <=, >=, etc.) are really just C++ functions that use a special syntax for listing the function arguments.

Let's consider an example of  a class called Money which will allow input and output in the form:  $123.45

Note that the input includes both the dollar sign and the decimal point.  Wouldn't it be nice to be able to have a main program which works with Money just as it it were a more simple data type?  Maybe with something as follows:



    .. activecode:: Cpp
      :caption: C++ Code
      :language: cpp

      //Program to demonstrate a simpler version of the class Money.
      #include <iostream>
      #include <fstream>
      #include <cstdlib>
      #include <cctype>
      using namespace std;

      //Class for amounts of money in U.S. currency.
      class Money
      {
      public:
          Money( );
          Money(long dollars);
          Money(long dollars, int cents);

          double get_value( ) const;

          friend bool operator ==(const Money& amount1, const Money& amount2);
          friend Money operator +(const Money& amount1, const Money& amount2);
          friend Money operator -(const Money& amount1, const Money& amount2);
          friend Money operator -(const Money& amount);

          friend istream& operator >>(istream& ins, Money& amount);
          //Overloads the >> operator so it can be used to input values of type Money.
          //Note that Money may not be negative in this version of the class
          //Precondition: If ins is a file input stream, then ins has already been
          //connected to a file.

          friend ostream& operator <<(ostream& outs, const Money& amount);
          //Overloads the << operator so it can be used to output values of type Money.
          //Precedes each output value of type Money with a dollar sign.
          //Precondition: If outs is a file output stream,
          //then outs has already been connected to a file.
      private:
          long all_cents;
      };

      int digit_to_int(char c);
      //Used in the definition of the overloaded input operator >>.
      //Precondition: c is one of the digits '0' through '9'.
      //Returns the integer for the digit; for example, digit_to_int('3') returns 3.

      int main( )
      {
          Money amount1, amount2;

          cout << "Enter some amount of money in the form $125.50, \nbeing sure to include the dollar sign: ";
          cin >> amount1;

          cout << "\nEnter another amount of money in the form $125.50, \nbeing sure to include the dollar sign: ";
          cin >> amount2;

          if (amount1==amount2)
             {cout << "\nThe two amounts entered are both equal to " << amount1 << ".\n"<< endl;}
          else
              {cout <<"\n" << amount1 << " is not the same as " << amount2 << ".\n"<< endl;}

          return 0;
      }

      Money::Money( ) : all_cents(0)
      {
          //Body intentionally blank.
      }

      Money::Money(long dollars) : all_cents(dollars*100)
      {
          //Body intentionally blank.
      }

      Money::Money(long dollars, int cents)
      {
          if(dollars*cents < 0) //If one is negative and one is positive
          {
              cout << "Illegal values for dollars and cents.\n";
              exit(1);
          }
          all_cents = dollars*100 + cents;
      }


      double Money::get_value( ) const
      {
          return (all_cents * 0.01);
      }

      bool operator ==(const Money& amount1, const Money& amount2)
      {
          return (amount1.all_cents == amount2.all_cents);
      }

      Money operator -(const Money& amount1, const Money& amount2)
      {
          Money temp;
          temp.all_cents = amount1.all_cents - amount2.all_cents;
          return temp;
      }

      Money operator -(const Money& amount)
      {
          Money temp;
          temp.all_cents = -amount.all_cents;
          return temp;
      }

      Money operator +(const Money& amount1, const Money& amount2)
      {
          Money temp;
          temp.all_cents = amount1.all_cents + amount2.all_cents;
          return temp;
      }

      //Uses iostream, cctype, cstdlib:
      istream& operator >>(istream& ins, Money& amount)
      {
          char one_char, decimal_point,
               digit1, digit2; //digits for the amount of cents
          long dollars;
          int cents;

          ins >> one_char; //if input is legal, then one_char == '$' and we do not store it
          ins >> dollars >> decimal_point >> digit1 >> digit2;

          if ( one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2) )
          {
              cout << "Error illegal form for money input.\n";
              exit(1);
          }

          cents = digit_to_int(digit1)*10 + digit_to_int(digit2);//Here we convert the cents
          amount.all_cents = dollars*100 + cents;  //Here we convert the money to all cents and store it in the private member variable
                                                   //The reason which we need this operator to be a friend is so it can access this member variable.
          return ins;
      }

      int digit_to_int(char c)
      {
          return ( int(c) - int('0') );
      }

      //Uses cstdlib and iostream:
      ostream& operator <<(ostream& outs, const Money& amount)
      {
          long positive_cents, dollars, cents;
          positive_cents = amount.all_cents;
          dollars = positive_cents/100;
          cents = positive_cents%100;

          outs << "$" << dollars << '.';

          if (cents < 10)
              outs << '0';
          outs << cents;

          return outs;
      }

.. datafile::  myid
    :edit:
    :rows: 20
    :cols: 65
    <iframe frameborder="0" width="100%" height="500px" src="https://repl.it/repls/StainedOffensiveTechnology"></iframe>


Let's look at the overloaded operator we use in this example.  The most complicated of the bunch is the overloaded instream operator, which is a friend of the class:

::

    istream& operator >>(istream& ins, Money& amount)
    {
        char one_char, decimal_point,
            digit1, digit2; //digits for the amount of cents
        long dollars;
        int cents;

        ins >> one_char; //if input is legal, then one_char == '$' and we do not store it
        ins >> dollars >> decimal_point >> digit1 >> digit2;

        if ( one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2) )
        {
            cout << "Error illegal form for money input.\n";
            exit(1);
        }

        cents = digit_to_int(digit1)*10 + digit_to_int(digit2);//Here we convert the cents
        amount.all_cents = dollars*100 + cents;  //Here we convert the money to all cents and store in the private member variable
                                                 //We need this operator to be a friend so it can access this member variable.
        return ins;
      }

Overloaded stream operators always have the stream both as a call-by-reference input as well as send-by-reference output.  This may seem weird, but the issue is that reading or writing a stream changes it.  The structure used the above example  will work BOTH for reading from the keyboard as well as from a file!

The overloaded outstream operator is also a friend, but is a bit simpler.  It can also be used as is to write to the screen or to a file!


    .. activecode:: Cpp4
      :caption: C++ Code
      :language: cpp


      ostream& operator <<(ostream& outs, const Money& amount)
      {
          long positive_cents, dollars, cents;
          positive_cents = amount.all_cents;
          dollars = positive_cents/100;
          cents = positive_cents%100;

          outs << "$" << dollars << '.';

          if (cents < 10)
              outs << '0';
          outs << cents;

          return outs;
      }

Once the Money is stored in the private member variable as all_cents, the boolean comparison, which is also a friend, is very simple:

::

    bool operator ==(const Money& amount1, const Money& amount2)
    {
      return (amount1.all_cents == amount2.all_cents);
    }


**General Rules**

1. Only existing operator symbols may be overloaded. New symbols that are not builtin, such as \*\*, cannot be used.
2. The operators ::, #, ., and ? are reserved and cannot be overloaded.
3. Some operators such as =, [], () and -> can only be overloaded as member functions of a class and not as global functions.
4. At least one operand for any overload must be a class or enumeration type. In other words, it is not possible to overload operators involving only built-in data types. For example, trying to overload the addition operator for the int data type would result in a compiler error:

    int operator +( int i, int j );  // This is not allowed

5. The number of operands for an operator may not be changed.
6. Operator precedence cannot be changed by overloading.


It is a good idea to match the overloaded operator implementation with the original meaning, even though mismatching is possible. In other words, it would be confusing if the + operator is overloaded to subtract values or if the << operator gets input from the stream.

In addition to being defined in within the class scope, overloaded operators may be defined in global or namespace scope or as friends of the class. Global scope means that the operator is defined outside of any function (including the main) or class. Namespace scope means that the operator is defined outside of any class but within a namespace, possibly within the main program.

One reason for declaring overloaded operators as friends of a class is that sometimes the operator is intimately related to a class but cannot be declared as a member of that class.
