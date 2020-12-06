#! /usr/bin/env bats

@test "Day1" {
  [ "$(cat $out/day1 | grep 'Part one = ')" = "Part one = 1016964" ]
  [ "$(cat $out/day1 | grep 'Part two = ')" = "Part two = 182588480" ]
}

@test "Day2" {
  [ "$(cat $out/day2 | grep 'Part one = ')" = "Part one = 378" ]
  [ "$(cat $out/day2 | grep 'Part two = ')" = "Part two = 280" ]
}

@test "Day3" {
  [ "$(cat $out/day3 | grep 'Part one = ')" = "Part one = 162" ]
  [ "$(cat $out/day3 | grep 'Part two = ')" = "Part two = 3064612320" ]
}

@test "Day4" {
  [ "$(cat $out/day4 | grep 'Part one = ')" = "Part one = 260" ]
  [ "$(cat $out/day4 | grep 'Part two = ')" = "Part two = 153" ]
}

@test "Day5" {
  [ "$(cat $out/day5 | grep 'Part one = ')" = "Part one = 919" ]
  [ "$(cat $out/day5 | grep 'Part two = ')" = "Part two = 642" ]
}
