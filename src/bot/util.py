import discord
import random

def dabnet_cmd_parse(data):
    LEGAL_COMMANDS = ['info', 'send', 'rate', 'greet']
    RATE_RESPONSES = ['yo shit mid as fuck my guy',
                      'this shit so purple it should be asking me where\'s Ronald',
                      'Jacob-tier cart you got here boyo',
                      'kill yourself']

    args = data.split(' ')
    if args[0] != 'dabnet' and args[0] not in LEGAL_COMMANDS:
        raise IllegalCommandException(args[0])

    if len(args) == 1:
        return 'dabnet WHAT fool?'

    #I know this is redundant, I don't care.
    match args[1]:
        case 'info':
            return 'DABnet: It\'s a hit! DABnet is a device that allows you to mix and match voltages on 3 different THC cartridges.'
        case 'send':
            return '[PLACEHOLDER]: starting DTP'
        case 'rate':
            response = random.randint(0, 3)
            return RATE_RESPONSES[response]
        case 'greet':
            return 'Hello!'
        case _:
            raise IllegalCommandException(args[1])


class IllegalCommandException(Exception):   
    def __init__(self, command):
        self.message = 'Illegal command: ' + command
        super().__init__(self.message)