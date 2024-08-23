# Write your MySQL query statement below
select * from Users
where mail REGEXP '^[A-Za-z][A-Za-z0-9._-]*@leetcode[.]*com$'

-- ^: Asserts the start of the string.
-- [A-Za-z]: Ensures the first character of the prefix is a letter (either uppercase A-Z or lowercase a-z).
-- [A-Za-z0-9._-]*: Matches zero or more of the allowed characters (letters, digits, underscores, periods, and dashes) in the prefix name.