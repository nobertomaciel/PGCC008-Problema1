import socket
import pickle
import numpy as np


from datetime import datetime

#Define o IP e a porta que serao utilizados para a troca de mensagens
meu_ip="10.0.0.129"
porta=555

# A partir de n_bkup mensagens recebidas eh feito o backup dos dados
n_bkup = 5

# Cria a conexao entre porta e ip para receber apcotes UDP
udp=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

servidor=(meu_ip, porta)

udp.bind(servidor)


# Estrutura de dados que armazena as informacoes recebidas
data = {"timestamps": [], "latitude":[], "longitude":[], "uv_sensor": [], "vb_sensor": [], "datahora":[]}

# Definindo Arquivo CSV com os dados dos sensores
csvfile = open('SensorData.csv','a')
np.savetxt(csvfile,[],header = 'timestamsps, latitude, longitude, uv_sensor, vb_sensor, datahora',delimiter=';',fmt='%s', comments='')

while(True):

        msg = udp.recv(1024)
        msg = msg.decode("utf8")
        msg_in = msg.split("@")
        msg_in[0] =str(msg_in[0])
        msg_in[1] =float(msg_in[1])
        msg_in[2] =float(msg_in[2])
        msg_in[3] =float(msg_in[3])
        msg_in[4] =float(msg_in[4])

        ts = datetime.utcfromtimestamp(int(msg_in[0])-(3600*3)).strftime("%Y-%m-%d@%H:%M:%S")

        msg_in.append(ts)

        np.savetxt(csvfile,[msg_in],delimiter=',',fmt='%s', comments='')

        ##########################################33

        data["timestamps"].append(msg_in[0])
        data["latitude"].append(msg_in[1])
        data["longitude"].append(msg_in[2])
        data["uv_sensor"].append(msg_in[3])
         data["vb_sensor"].append(msg_in[4])
        data["datahora"].append(ts)

        print("Orignal", msg)

        print("Message:")
        print("##########")
        print("timestamps", data["timestamps"])
        print("latitude", data["latitude"])
        print("longitude", data["longitude"])
        print("UV sensor", data["uv_sensor"] )
        print("vibration", data["vb_sensor"])
        print("")
        print("")
        
udp.close()
