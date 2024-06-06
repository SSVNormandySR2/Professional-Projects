;Vincent Latona

;Q1 (10 points)
;1.1 encryption (5 points)
(display "Enter encryption key (key can be between 1 and 4):")

;key for encryption
(define key (read))

;encrypt procedure
(define (encrypt str)

  ;let form for local procedure
  (let

      ;Let definitions
      (

       ;char-encrypt let-defined procedure
       (char-encrypt

        ;Lambda expression
        (lambda (char)

          ;Alphabetic/Numeric verification
          (if (char-alphabetic? char)

              ;Return char manipulation
              (integer->char (+ (char->integer char) key))

              ;Numeric verification
              (if (and (char>=? char #\0) (char<=? char #\9))

                  ;Return char+key
                  (integer->char (+ (char->integer char) key))

                  ;Return char unchanged
                  char

              );End of numeric verification

          );End of alphabetic/numeric verification
              
        );End of lambda expression

       );End of let-defined procedure char-encrypt

      );End of let definitions

    ;Key range verification for encryption
    (if (and (>= key 1) (<= key 4)) (list->string (map char-encrypt (string->list str))))
    
  );End of let form
    
);End of procedure encrypt

;1.2 decryption (5 points)
;decrypt procedure
(define (decrypt str)

  ;let form for local procedure
  (let

      ;Let definitions
      (

       ;char-decrypt let-defined procedure
       (char-decrypt

        ;Lambda expression
        (lambda (char)

          ;Alphabetic/Numeric verification
          (if (char-alphabetic? char)

              ;Return char manipulation
              (integer->char (- (char->integer char) key))

              ;Numeric verification
              (if (and (char>=? char #\0) (char<=? char #\9))

                  ;Return char-key
                  (integer->char (- (char->integer char) key))

                  ;Return char unchanged
                  char

              );End of numeric verification

          );End of alphabetic/numeric verification
              
        );End of lambda expression

       );End of let-defined procedure char-encrypt

      );End of let definitions

    ;Key range verification for decryption
    (if (and (>= key 1) (<= key 4)) (list->string (map char-decrypt (string->list str))))
    
  );End of let form
  
);End of procedure decrypt

; Test cases
(encrypt "Hello CSE240!")
(decrypt (encrypt "Hello CSE240!"))
(encrypt "Ifmmp DTF351!")
(decrypt (encrypt "Ifmmp DTF351!"))
(encrypt "Go Devils 2021!")
(decrypt (encrypt "Go Devils 2021!"))

;Enter encryption key (key can be between 1 and 4):3
;"Khoor FVH573!"
;"Hello CSE240!"
;"Lipps GWI684!"
;"Ifmmp DTF351!"
;"Jr Ghylov 5354!"
;"Go Devils 2021!"

;Q2.1 (3 points)
;OR-GATE procedure
(define (OR-GATE a b)

  ;Logic evaluation
  (if (or (= a 1) (= b 1))

      ;1 for all other combinations
      1

      ;0 for a=b=0
      0

  );End of logic evaluation

);End of procedure OR-GATE
                  
;AND-GATE procedure
(define (AND-GATE a b)

  ;Logic evaluation
  (if (and (= a 1) (= b 1))

      ;1 for a=b=1
      1

      ;0 for all other combinations
      0

  );End of logic evaluation

);End of procedure AND-GATE

;XOR-GATE procedure
(define (XOR-GATE a b)

  ;Logic evaluation
  (if (or (and (= a 1) (= b 0)) (and (= a 0) (= b 1)))

      ;1 for odd number of 1's
      1

      ;0 for even number of 1's or all 0's
      0

  );End of logic evaluation

);End of procedure XOR-GATE

;Test cases
(newline)
(AND-GATE 0 0)
(AND-GATE 0 1)
(AND-GATE 1 0)
(AND-GATE 1 1)

;0
;0
;0
;1

(newline)
(OR-GATE 0 0)
(OR-GATE 0 1)
(OR-GATE 1 0)
(OR-GATE 1 1)

;0
;1
;1
;1

(newline)
(XOR-GATE 0 0)
(XOR-GATE 0 1)
(XOR-GATE 1 0)
(XOR-GATE 1 1)

;0
;1
;1
;0

;Q2.2 
;Q2.2.1: (2 points each)
;sum-bits procedure
(define (sum-bits x a b)

  ;Bit addition
  (XOR-GATE x (XOR-GATE a b))

);End of sum-bits procedure

;Q2.2.2: (2 points each)
;carry-out procedure
(define (carry-out x a b)

  ;Carry-out logic
  (OR-GATE (OR-GATE (AND-GATE x a) (AND-GATE x b)) (AND-GATE a b))

);End of carry-out procedure

;Q2.2.3: (3 points each)
;bitAdder procedure
(define (bitAdder x a b)

  ;Sum and Carry-out construction
  (cons (sum-bits x a b) (carry-out x a b))

);End of bitAdder procedure

;Test cases
(newline)
(bitAdder 0 0 0) 	
(bitAdder 0 0 1) 	
(bitAdder 0 1 0) 	
(bitAdder 0 1 1)	
(bitAdder 1 0 0) 	
(bitAdder 1 0 1)	
(bitAdder 1 1 0) 	
(bitAdder 1 1 1) 

;(0 . 0)
;(1 . 0)
;(1 . 0)
;(0 . 1)
;(1 . 0)
;(0 . 1)
;(0 . 1)
;(1 . 1)

;Q3.1 (4 points)
;tail procedure
(define (tail lst)

  ;Recursive let-form
  (letrec

      ;let-form definition
      (

       ;let-defined reverse procedure
       (reverse

        ;Lambda expression
        (lambda (L)

          ;Stopping evaluation
          (if (null? L)

              ;Stop at empty list
              '()

              ;Form reverse list with recursive call
              (append (reverse (cdr L)) (list (car L)))

          );End of stopping evaluation

        );End of lambda expression

       );End of let-defined procedure reverse

      );End of let-form definition

    ;Return last element
    (car (reverse lst))

  );End of recursive let-form

);End of procedure tail

;Q3.2 (4 points)
;rmtail procedure
(define (rmtail lst)

  ;Recursive let-form
  (letrec

      ;let-form definition
      (

       ;let-defined reverse procedure
       (reverse

        ;Lambda expression
        (lambda (L)

          ;Stopping evaluation
          (if (null? L)

              ;Stop at empty list
              '()

              ;Form reverse list with recursive call
              (append (reverse (cdr L)) (list (car L)))

          );End of stopping evaluation

        );End of lambda expression

       );End of let-defined procedure reverse

      );End of let-form definition

    ;Return the list, excluding the last element
    (reverse (cdr (reverse lst)))

  );End of recursive let-form

);End of procedure rmtail

;Q3.3 (4 points)
;Answer the questions in the form of comments
;(1) The n-size problem is the summation of 2 bit-strings of length-n
;(2) The stopping condition is when you have no more bits to add, thus returning the last carry-in
;(3) The size-(n-1) problem is the summation of the bit-strings of length-(n-1)
;(4) The solution of the size-n problem from the size-(n-1) problem is to
;    construct a list of the individual bit-sums and final carry-in

;Q3.4 (18 points)
(define X1 '(0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0) )	
(define X2 '(1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1) )	
(define X3 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1) )	
(define X4 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0) )
(define X5 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1) )	
(define X6 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1) )

;n-bit-adder1 procedure
(define (n-bit-adder1 L1 L2 n)

  ;Begin addition with carry-in of 0
  (n-bit-adderhelper1 L1 L2 n 0)

);End of procedure n-bit-adder1

;n-bit-adderhelper1 procedure
(define (n-bit-adderhelper1 L1 L2 n c-in)

  ;Stopping condition at last carry-in
  (if (= n 0)

      ;Make sub-list of final carry-in
      (list (list c-in))

      ;Let-form
      (let

          ;let-form definition
          (

           ;sum from adder
           (sum (car (bitAdder (tail L1) (tail L2) c-in)))

           ;c-out from adder
           (c-out (cdr (bitAdder (tail L1) (tail L2) c-in)))

          );End of let-form definition

        ;List creation of recursive call and sum
        (append (n-bit-adderhelper1 (rmtail L1) (rmtail L2) (- n 1) c-out) (list sum))

      );End of let-form

  );End of stopping condition evaluation

);End of procedure n-bit-adderhelper1

;Test cases
(newline)
(n-bit-adder1  X1 X2 32)
(n-bit-adder1  X3 X4 32)
(n-bit-adder1  X5 X6 32)
(n-bit-adder1  X2 X3 32)
(n-bit-adder1  X4 X5 32)
(n-bit-adder1  X1 X6 32)
(newline)
(n-bit-adder1  X1 X3 32)
(n-bit-adder1  X1 X4 32)
(n-bit-adder1  X1 X5 32)
(n-bit-adder1  X2 X4 32)
(n-bit-adder1  X2 X5 32)
(n-bit-adder1  X2 X6 32)

;((0) 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1)
;((0) 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1)
;((1) 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0)
;((1) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0)
;((1) 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1)
;((0) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1)

;((0) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1)
;((0) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0)
;((0) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1)
;((1) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0 1)
;((1) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 0)
;((1) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0)



