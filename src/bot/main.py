import discord
from util import *
import securetoken

intents = discord.Intents.default()
intents.message_content = True

client = discord.Client(intents=intents)

@client.event
async def on_ready():
    print('We have loggied in as {0.user}'.format(client))
    print([channel.name for channel in client.get_all_channels() if isinstance(channel, discord.TextChannel)])

@client.event
async def on_message(message):
    if message.author == client.user:
        return

    await message.channel.send(dabnet_cmd_parse(message.content))

client.run(securetoken.token)