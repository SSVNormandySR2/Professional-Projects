/*
 New ID for user
 */
select max(u.userID) from Users as u;

/*
 User registration
 */
insert into Users values(uid, mail, first, last, birthdate, town, gen, hashPass);

/*
 User Login Validation
 */
select u.userID
from Users as u
where u.email = 'user email' /* insert email input */
and u.password = 'hashed password'; /* insert hashed password */

/*
 Friend Search
 */
select u.userID, u.firstName, u.lastName
from Users as u
where u.firstName = 'insert first name' /* insert first name */
and u.lastName = 'insert last name'; /* insert last name */

/*
 List of following
 */
select f.followedID
from Friends as f
where f.followerID = n; /* current user ID */

/*
 List of followers
 */
select f.followerID
from Friends as f
where f.followedID = n; /* current user ID */

/*
 Add friend
 */
 insert into Friends values(user, newFriend, date);

/*
 * Contribution scoring
 */
select u1.userID, u1.firstName, u1.lastName, ifnull(pCount,0)+ifnull(cCount,0) as score from
Users as u1 left join /* left join users and comments */
(select distinct u.userID as id, ifnull(count(*),0) as cCount from Users as u, Comments as c
where c.ownerID = u.userID
group by u.userID) as com
on com.id = u1.userID
left join /* left join all results to get score for all users */
(select distinct u2.userID as id, ifnull(count(*),0) as pCount from Users as u2, Photos as p2, Albums as a2
where p2.albumID = a2.albumID and a2.ownerID = u2.userID
group by u2.userID) as pho
on pho.id = u1.userID
order by score desc
limit 10;

 /*
  Public album browsing
  */
select * from Albums;

/*
 Private album browsing
 */
select a.albumID, a.ownerID, a.albumName, a.dateOfCreation
from Albums as a, Photos as p where a.ownerID = n and p.albumID = a.albumID;

/*
 Verify album ID for deletion/update
 */
select a.albumID from Albums as a where a.ownerID = uid;

/*
 New ID for album
 */
select max(a.albumID) from Albums as a;

/*
 Add album
 */
insert into Albums values(aid, uid, name, doc);

/*
 Album update
 */
update Albums as a set a.albumName = 'newname' where a.albumID = aid;

/*
 Album delete
 */
delete from Albums as a where a.albumID = aid;

/*
 Public photo browsing
 */
select p.photoID, p.albumID, p.caption
from Photos as p;

/*
 Private photo browsing
 */
select p.photoID, p.albumID, p.caption
from Photos as p, Albums as a
where p.albumID = a.albumID /* join photos and albums */
and a.ownerID = n; /* current user ID for album owner */

/*
 Validate photo ID for deletion
 */
select p.photoID from Photos as p, Albums as a where p.albumID = a.albumID
and a.ownerID = uid;

/*
 New ID for photo
 */
select max(p.photoID) from Photos as p;

/*
 Add photo
 */
insert into Photos values(pid, aid, cap, data);

/*
 Delete photo
 */
delete from Photos as p where p.photoID = pid;

/*
 Photo viewing information
 */
select p.photoID, p.caption, p.loc from Photos as p
where p.PhotoID = n;

/*
 Count likes for photo
 */
select count(*) from Likes as l where l.photoID = n;

/*
 Add like
 */
 insert into Likes values(n, pid);

/*
 Users who like a photo
 */
select u.userID, u.firstName, u.lastName from Users as u, Likes as l
where l.photoID = n and l.userID = u.userID;

/*
 Private photo browsing by tag
 */
select p.photoID, p.caption
from Photos as p, Tags as t, Albums as a
where p.photoID = t.photoID /* join photos and tags */
and t.tag = 'tag' /* insert tag data */
and p.albumID = a.albumID /* join photos and albums */
and a.ownerID = n; /* current user ID for album owner */

/*
 Public photo browsing by tag
 */
select p.loc, p.photoID
from Photos as p, Tags as t
where p.photoID = t.photoID /* join photos and tags */
and t.tag = 'tag'; /* insert tag data */

/*
 Most popular tags
 */
select t.tag, count(*) /* count tag occurrences */
from Tags as t
group by t.tag /* group by tag data */
order by count(t.tag) desc; /* order by most popular */

/*
 Add tag
 */
insert into Tags values(pid, text);

/*
 All possible tags
 */
select distinct t.tag from Tags as t;

/*
 Photo search - conjunctive tag search
 repeat intersection/inner join for n tags
 */
select p.loc, p.photoID
from Photos as p,
(select p1.photoID as photo
from Photos as p1, Tags as t1
where p1.photoID = t1.photoID /* join photos and tags */
and t1.tag = 'tag1') as a /* insert tag data */
inner join /* inner join tags on same photo ID */
(select pn.photoID as photo
from Photos as pn, Tags as tn
where pn.photoID = tn.photoID /* join photos and tags */
and tn.tag = 'tagn') as b /* insert tag data */
on a.photo = b.photo
where a.photo = p.photoID; /* join tagged photos and photos */

/*
 View likes per photo
 */
select count(*)
from Likes as l
where l.photoID = n /* insert current photo ID */
group by l.photoID;

/*
 View comments for a photo
 */
select u.userID, u.firstName, u.lastName, c.text, c.dateOfComment
from Users as u, Comments as c where c.photoID = pid and c.ownerID = u.userID;

/*
 New ID for comment
 */
select max(c.commentID) from Comments as c;

/*
 Add comment to photo
 */
insert into Comments values(cid, uid, pid, content, doc);

/*
 Comment search
 */
select u.firstName, u.lastName, count(*) as matched
from Users as u, Comments as c
where u.userID = c.ownerID
and c.text = 'text' /* insert comment text */
group by c.ownerID
order by count(*) desc;

/*
 Friends of Friends
*/
select f.followedID, u.firstName, u.lastName, count(*) as commonFriends from Users as u, Friends as f /* find people who are*/
where u.userID = f.followedID and f.followerID in
(select f1.followedID from Friends as f1 /* friends of friends of current user */
where f1.followerID = n) and f.followedID not in
(select f2.followedID from Friends as f2 /* and are not already friends with the current user */
where f2.followerID = n)
and f.followedID != n /* don't include current user */
group by f.followedID
order by commonFriends desc;

/*
 You-may-also-like Recommendations
 */
select nonUserTags.photo, count(*) as score from
(select distinct t1.tag as tag, count(*) as occurrence /* get top 5 tags from user photos */
from Users as u1, Albums as a1, Photos as p1, Tags as t1
where u1.userID = n /* current user ID for top user tags */
and u1.userID = a1.ownerID /* join current user and their albums */
and a1.albumID = p1.albumID /* join user albums and photos */
and p1.photoID = t1.photoID /* join user photos and tags */
group by t1.tag /* group by tag occurrences */
order by occurrence desc
limit 5) as userTags
inner join /* join on non-user photos */
(select t.photoID as photo, t.tag as tag from Tags as t, Photos as p, Albums as a
where t.photoID = p.photoID and p.albumID = a.albumID and a.ownerID != n) as nonUserTags
on userTags.tag = nonUserTags.tag
group by nonUserTags.photo /* group by photo occurrence */
order by score desc;