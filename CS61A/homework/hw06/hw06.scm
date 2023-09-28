(define (cddr s) (cdr (cdr s)))

(define (cadr s) (car (cdr s)))

(define (caddr s) (car (cdr (cdr s))))

(define (sign val) (cond ((< val 0) -1)
                        ((= val 0) 0)
                        (#t 1)))

(define (square x) (* x x))

(define (pow base exp) 
    (
        if (= exp 1) base
        (if (even? exp) 
            (
                square (pow base (/ exp 2))
            )
            (
                * base (square (pow base (floor (/ exp 2))))
            )
        )
    )
)

(define (pow x y) 
    'YOUR-CODE-HERE
    (if (= y 1) x
        (if (even? y) 
            (square (pow x (/ y 2)))
            (* x (square (pow x (floor (/ y 2)))))
        )
    )
)
