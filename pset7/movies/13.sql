select name
from people join stars
on people.id = stars.person_id
where name != 'Kevin Bacon' and movie_id in (
    select movie_id
    from stars
    where person_id in (
        (
            select id
            from people
            where name = 'Kevin Bacon'
                and birth = 1958
        )
    )
);