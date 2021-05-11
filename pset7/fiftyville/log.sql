-- Keep a log of any SQL queries you execute as you solve the mystery.

-- find details of incident took place
select * from crime_scene_reports where year = 2020 and month = 7 and day = 28 and street = "Chamberlin Street";

-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
-- Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

-- retrieve interview transcripts
select name, transcript from interviews where year = 2020 and month = 7 and day = 28 and transcript like "%courthouse%";

--Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
--       If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
--Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
--         I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
--Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say
--          that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the
--          phone to purchase the flight ticket.


-- Query Ruth statement
select activity, license_plate, hour, minute from courthouse_security_logs where year = 2020 and month = 7 and day = 28 and hour = 10 and minute > 15 and minute < 30;
--exit cars at that time
--exit | 5P2BI95 | 10 | 16
--exit | 94KL13X | 10 | 18
--exit | 6P58WS2 | 10 | 18
--exit | 4328GD8 | 10 | 19
--exit | G412CB7 | 10 | 20
--exit | L93JTIZ | 10 | 21
--exit | 322W7JE | 10 | 23
--exit | 0NTHK55 | 10 | 23

-- Query Eugene statement
select name, phone_number, passport_number, license_plate
from people
where id in (
    select person_id
    from bank_accounts
    where account_number in (
        select account_number
        from atm_transactions
        where year = 2020 and month = 7 and day = 28 and atm_location = "Fifer Street" and transaction_type="withdraw"
        )
)
and
license_plate in (
    select license_plate
    from courthouse_security_logs
    where year = 2020 and month = 7 and day = 28 and hour = 10 and minute > 15 and minute < 30
);

--name | phone_number | passport_number | license_plate
--Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
--Danielle | (389) 555-5198 | 8496433585 | 4328GD8
--Russell | (770) 555-1861 | 3592750733 | 322W7JE
--Ernest | (367) 555-5533 | 5773159633 | 94KL13X

-- Query Raymond statement
select caller, receiver, duration
from phone_calls
where year = 2020 and month = 7 and day = 28 and duration < 60 and caller in (
select phone_number
from people
where id in (
    select person_id
    from bank_accounts
    where account_number in (
        select account_number
        from atm_transactions
        where year = 2020 and month = 7 and day = 28 and atm_location = "Fifer Street" and transaction_type="withdraw"
        )
)
and
license_plate in (
    select license_plate
    from courthouse_security_logs
    where year = 2020 and month = 7 and day = 28 and hour = 10 and minute > 15 and minute < 30
)
);

--caller | receiver | duration
--(367) 555-5533 | (375) 555-8161 | 45
--(770) 555-1861 | (725) 555-3243 | 49

-- find airports for the above number (caller) passport number
select *
from flights
where id in (
        select flight_id
        from passengers
        where passport_number in (5773159633, 3592750733)
)
and year = 2020 and month = 7 and day = 29;

--id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
--18 | 8 | 6 | 2020 | 7 | 29 | 16 | 0
--36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20
-- as the earliest flight is booked, so it should be the second one

--find destination information as
select * from airports where id = 4;




