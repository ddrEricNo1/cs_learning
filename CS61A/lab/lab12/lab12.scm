(define (tail-replicate x n)
  'YOUR-CODE-HERE
  (define (helper cur i)
    (if (= i n)
        `(,@cur ,x)
        (helper `(,@cur ,x) (+ i 1))
    )
  )
  (if (= n 0)
      '()
      (helper '() 1)
  )
)

(define-macro (def func args body)
  'YOUR-CODE-HERE
  `(define (,func ,@args) ,body)
)

(define (repeatedly-cube n x)
  (if (zero? n)
      x
      (let ((y (repeatedly-cube (- n 1) x))
           )
        (* y y y)
      )
  )
)
