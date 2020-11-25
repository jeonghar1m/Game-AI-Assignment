; red-prob2.pddl

(define (problem red-prob2) (:domain redriding) 
(:objects red wolf home granny-house woods fair
)

(:init
    (person red) (at red home) (at wolf woods)
    (know-path red woods) 
    (know-path red granny-house)
)

(:goal (and (at red woods) (greeting red wolf) (know-path wolf granny-house)
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)