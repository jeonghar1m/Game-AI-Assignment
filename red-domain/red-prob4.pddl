; red-prob4.pddl

(define (problem red-prob4) (:domain redriding) 
(:objects red wolf granny home granny-house woods fair flowers
)

(:init
    (person red) (at red woods) (at wolf woods) (at granny granny-house)

    (know-path red granny-house) (know-path wolf granny-house)
)

(:goal (and (greeting red wolf) (know-path wolf granny-house)  (at wolf granny-house) (eat wolf granny) (at red granny-house) (eat wolf red)
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)