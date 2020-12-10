--In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
--Your query should output a table with a single column for the name of each person.
--There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
--Kevin Bacon himself should not be included in the resulting list.
--Kevin Bacon Person id - 102
-- Total 58 movies to be listed

--Query to find Kevin Bacon Titles by person_id
SELECT name
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE title IN
(SELECT DISTINCT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.name ="Kevin Bacon" AND people.birth = 1958 GROUP BY movies.id)
AND name !="Kevin Bacon"
GROUP BY people.id;



--SELECT count(title)
--FROM movies
--JOIN stars ON movies.id = stars.movie_id
--JOIN people ON people.id = stars.person_id
--WHERE title IN
--(SELECT title
--FROM movies
--JOIN stars ON movies.id = stars.movie_id
--JOIN people ON stars.person_id = people.id
--WHERE person_id = 102)
--ORDER BY name ASC;

