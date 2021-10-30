const test = require('ava')
const {comparator} = require('./ar-rpprscs')

test('comparator should return 0 when both options are equal', (t) => {
  t.is(comparator('paper', 'paper'), 0)
  t.is(comparator('scissors', 'scissors'), 0)
  t.is(comparator('rock', 'rock'), 0)
})

test('comparator should return 1 when option 1 is "paper" and option 2 is "rock', (t) => {
  t.is(comparator('paper', 'rock'), 1)
})

test('comparator should return 1 when option 1 is "scissors" and option 2 is "paper', (t) => {
  t.is(comparator('scissors', 'paper'), 1)
})

test('comparator should return 1 when option 1 is "rock" and option 2 is "scissors', (t) => {
  t.is(comparator('rock', 'scissors'), 1)
})

test('comparator should return 1 when option 1 is "rock" and option 2 is "paper', (t) => {
  t.is(comparator('rock', 'paper'), -1)
})

test('comparator should return 1 when option 1 is "paper" and option 2 is "scissors', (t) => {
  t.is(comparator('paper', 'scissors'), -1)
})

test('comparator should return 1 when option 1 is "scissors" and option 2 is "rock', (t) => {
  t.is(comparator('scissors', 'rock'), -1)
})
