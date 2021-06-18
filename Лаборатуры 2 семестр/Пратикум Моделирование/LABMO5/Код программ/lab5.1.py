import pickle
import  json
Sing = {
    'name':'Michael Jackson',
    'track': ['Оптимист', 'You Rock My world'],
    'albums':[{'name': 'Invincible' ,'year': '2001'}]

}
print(type (Sing))
with open ('music.json', 'w', encoding='utf-8') as f:
    json.dump(Sing, f)

with open('music.pickle', 'wb') as f:
    pickle.dump(Sing, f)
    print('запись выполнена')