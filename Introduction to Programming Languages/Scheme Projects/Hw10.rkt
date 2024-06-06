; Vincent Latona

; Q1 (5 points)
;1.1 : 9 * 3 + 5 - 7 (Standard Order of Operations)
(- (+ (* 9 3) 5) 7)

;1.2 : 5 * (2 + 8) * (10 - 2 - 5) + 15
(+ (* 5 (+ 2 8) (- 10 2 5)) 15)

;1.3 : 9 * ((5 + (48 / 8)) - (3 * (7 + 9))) / 2
(/ (* 9 (- (+ 5 (/ 48 8)) (* 3 (+ 7 9)))) 2)

;1.4 : 3 * (9 + (((2 + (32 / 4) - (2 * 5))) * (10 - 2)))
(* 3 (+ 9 (* (- (+ 2 (/ 32 4)) (* 2 5)) (- 10 2))))

;1.5 : ((((((4 + 5) * (6 + 7)) * 2) * 2) - 10) / 2) - ((3 * ((4 * 5) + (6 * 4)) / 2) + (4 * 5))
(- (/ (- (* (* (* (+ 4 5) (+ 6 7)) 2) 2) 10) 2) (+ (/ (* 3 (+ (* 4 5) (* 6 4))) 2) (* 4 5)))


; Q2 (5 points)
;Division procedure
(define (Divide x y)

  ;Procedure execution
  (/ x y)
  
);End of procedure Divide

;Test case
(Divide 10 3)


; Q3 (5 points)
;nDivide procedure
(define (nDivide x y n)

  ;Stopping condition evaluation
  (if (= n 1)

      ;Final division
      (Divide x y)

      ;Recursive call
      (Divide (nDivide x y (- n 1)) y)
      
  );End of stopping condition evaluation

);End of procedure nDivide

;Test case
(nDivide 10 3 4)


; Q4: Please enter test values 10 3 and 4. It should return 10/81. (5 points)
(display "Enter 10 3 4 as test case. It returns 10/81")
(newline)

;ReadForDivide procedure
(define (ReadForDivide)

  ;Unnamed procedure for input reading
  ((lambda (x y n) (nDivide x y n)) (read) (read) (read))
  
);End of procedure ReadForDivide
  
;Test case
(ReadForDivide)

  
; Q5 (5 points)
;DividenDivide procedure
(define (DividenDivide u v x y n)

  ;Procedure execution
  (Divide (nDivide u v n) (nDivide x y n))

);End of procedure DividenDivide

;Test case
(DividenDivide 64 2 10 3 4)

  
;Q6 (5 points)
;DividenDivideLet procedure
(define (DividenDivideLet u v x y n)

  ;Outer let form
  (let

      ;Outer let form definition
      (

       ;Let-defined DivideLet procedure
       (DivideLet (lambda (x y)

                    ;DivideLet execution
                    (/ x y)
                    
                  );End of lambda expression
                  
       );End of procedure DivideLet
       
      );End of outer let definition

    ;Inner recursive let form
    (letrec

        ;Inner let form definition
        (

         ;Recursive let-defined nDivideLet procedure
         (nDivideLet (lambda (x y n)

                       ;Stopping condition evaluation
                       (if (= n 1)

                           ;Final divide
                           (DivideLet x y)

                           ;Recursive call
                           (DivideLet (nDivideLet x y (- n 1)) y)

                       );End of stopping condition evaluation
                       
                     );End of lambda expression

         );End of procedure nDivideLet

        );End of inner let form definition

      ;DividenDivideLet execution
      (DivideLet (nDivideLet u v n) (nDivideLet x y n))

      );End of inner let form

  );End of outer let form
  
);End of procedure DividenDivideLet

;Test case
(DividenDivideLet 64 2 10 3 4)


; Q7: Enter values 1 4 3 2 5 10 7 8 and it should return 16. (10 points)
(display "Enter 1 4 3 2 5 10 7 8 and end, and it returns 16.")
(newline)

;accumulator procedure
(define (accumulator oddsum next)

  ;Stopping condition evaluation
  (if (number? next)

      ;Odd check
      (if (not(= (remainder next 2) 0))

          ;Increment oddsum and call recursively
          (accumulator (+ oddsum next) (read))

          ;Recursive call
          (accumulator oddsum (read))

      );End of odd check

      ;Stop and return sum
      (+ oddsum 0)

  );End of stopping condition evaluation

);End of procedure accumulator

;Test case  
(accumulator 0 0) 