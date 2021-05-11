Select title
from movies
where id in (
        select movie_id
        from stars
        where person_id in (
            select id
            from people
            where name = "Johnny Depp"
        )
        INTERSECT
        select movie_id
        from stars
        where person_id in (
            select id
            from people
            where name = "Helena Bonham Carter"
        )
    );