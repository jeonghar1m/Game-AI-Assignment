;red-domain

(define (domain redriding)

;remove requirements that are not needed
(:requirements :strips)

; un-comment following line if constants are needed
;(:constants )

(:predicates (at ?who ?where)
            (person ?who)
            (location ?where)
            (greeting ?who1 ?who2)
            (know-path ?who ?loc)
            (pick ?who ?obj)
            (eat ?who1 ?who2)
)

(:action goto
        :parameters (?who ?from ?to)
        :precondition (and (at ?who ?from) (know-path ?who ?to))
        :effect (and (at ?who ?to))
)

(:action meet
        :parameters (?who1 ?who2 ?loc)
        :precondition (and (at ?who1 ?loc) (at ?who2 ?loc))
        :effect (and (greeting ?who1 ?who2))
)

(:action tell-path
        :parameters (?who1 ?who2 ?loc)
        :precondition (and (greeting ?who1 ?who2) (know-path ?who1 ?loc))
        :effect (and (know-path ?who2 ?loc))
)

(:action pick-up
        :parameters (?who ?obj)
        :precondition (and  )
        :effect (and (pick ?who ?obj))
)

(:action eat-alive
        :parameters (?who1 ?who2)
        :precondition (and (greeting ?who1 ?who2))
        :effect (and (eat ?who1 ?who2))
)

(:action sleep
        :parameters (?who)
        :precondition (and )
        :effect (and )
)

(:action snore-loud
    :parameters (?who)
    :precondition (and )
    :effect (and )
)

(:action check
    :parameters (?who ?noise)
    :precondition (and )
    :effect (and )
)

(:action delivery
    :parameters (?who1 ?who2 ?obj)
    :precondition (and )
    :effect (and )
)

(:action eat-together
    :parameters (?who1 ?who2 ?who3 ?obj)
    :precondition (and )
    :effect (and )
)



;define actions here

)
