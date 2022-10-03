const inquirer = require('inquirer')

const options = ['paper', 'rock', 'scissors']

const randomOption = () => {
  const index = Math.floor(Math.random() * options.length)
  return options[index]
}

const comparator = (a, b) => {
  if (a === b) return 0
  if (
    (a === 'paper' && b === 'rock') ||
    (a === 'scissors' && b === 'paper') ||
    (a === 'rock' && b === 'scissors')
  ) {
    return 1
  }
  return -1
}

const prompt = inquirer.createPromptModule()

const play = () => {
  console.log('Welcome to the Rock Paper Scissors')
  console.log('----------------------------------')

  prompt({
    type: 'list',
    name: 'userOption',
    message: 'Choose your move.',
    choices: [
      {name: 'Rock', value: 'rock'},
      {name: 'Paper', value: 'paper'},
      {name: 'Scissors', value: 'scissors'},
    ],
  }).then(({userOption}) => {
    console.log(`You choose: ${userOption}`)
    const computerOption = randomOption()
    console.log(`Computer choose: ${computerOption}`)
    const result = comparator(userOption, computerOption)
    if (result === 1) {
      console.log('YOU WON')
    } else if (result === -1) {
      console.log('COMPUTER WON')
    } else {
      console.log('DRAW')
    }
  })
}

module.exports = {comparator, play}
