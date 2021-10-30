import inquirer from 'inquirer'

type Option = 'paper' | 'rock' | 'scissors'

const options: Option[] = ['paper', 'rock', 'scissors']

const randomOption = () => {
  const index = Math.floor(Math.random() * options.length)
  return options[index]
}

export const comparator = (a: Option, b: Option) => {
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

export const play = async () => {
  console.log('Welcome to the Rock Paper Scissors')
  console.log('----------------------------------')

  const {userOption}: {userOption: Option} = await prompt({
    type: 'list',
    name: 'userOption',
    message: 'Choose your move.',
    choices: [
      {name: 'Rock', value: 'rock'},
      {name: 'Paper', value: 'paper'},
      {name: 'Scissors', value: 'scissors'},
    ],
  })
  console.log(`You choose: ${userOption}`)
  const computerOption: Option = randomOption()
  console.log(`Computer choose: ${computerOption}`)
  const result: -1 | 0 | 1 = comparator(userOption, computerOption)
  if (result === 1) {
    console.log('YOU WON')
  } else if (result === -1) {
    console.log('COMPUTER WON')
  } else {
    console.log('DRAW')
  }
}
