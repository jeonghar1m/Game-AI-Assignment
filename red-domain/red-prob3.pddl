; red-prob3.pddl

(define (problem red-prob3) (:domain redriding) 
(:objects red wolf granny home granny-house woods fair flowers
)

(:init
    (person red) (at red woods) (at wolf woods) (at granny granny-house)
    (know-path red woods) 
    (know-path red granny-house)
)

(:goal (and (greeting red wolf) (know-path wolf granny-house) (at wolf granny-house) (eat wolf granny)
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)