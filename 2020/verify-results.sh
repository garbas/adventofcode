#! /usr/bin/env bats

@test "Day1 - Part one" {
  [ "$(cat $out/day1 | grep 'Part one = ')" = "Part one = 1016964" ]
}

@test "Day1 - Part two" {
  [ "$(cat $out/day1 | grep 'Part two = ')" = "Part two = 182588480" ]
}

@test "Day2 - Part one" {
  [ "$(cat $out/day2 | grep 'Part one = ')" = "Part one = 378" ]
}

@test "Day2 - Part two" {
  [ "$(cat $out/day2 | grep 'Part two = ')" = "Part two = 280" ]
}

#@test "Day3 - Part one" {
#  [ "$(cat $out/day3 | grep 'Part one = ')" = "Part one = 1016964" ]
#}
#
#@test "Day3 - Part two" {
#  [ "$(cat $out/day3 | grep 'Part two = ')" = "Part two = 182588480" ]
#}
