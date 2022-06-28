# PGCC008 - Sistemas Computacionais 2022-1 <br>Atividade #1: Detecção de Emergências


## Descrição:
<!-- ## Description: -->
<ul>
   <li>
      <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/job_description.pdf">job_description.pdf</a>
   </li>
</ul>

## Diagramas do projeto:
<!-- ## Project diagrams: -->
<p>
   <img width="600px" src="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/diagrams/PGCC008_Atividade-1_structure.png">
</p>
<p>
   <img width="960px" src="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/diagrams/PGCC008_Atividade-1_physical.png">
</p>


## NodeMCU ESP8266 v3:
### Códigos
<!-- ### Source codes -->
<ul>
    <li>
       <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/src/PGCC008_atividade_sensor/PGCC008_atividade_sensor.ino">
         Código fonte para cada nó de sensores (endDevices)
<!--          Source code to each sensors node (endDevices) -->
       </a>
   </li>
    <li>
      <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/src/PGCC008_atividade_host/PGCC008_atividade_host.ino">
         Código fonte para teste do nodeMCU como host (Sink test) 
<!--          Source code to testing host on nodeMCU (Sink test) -->
      </a>
   </li>
</ul>


### Configuração
<!-- ### Configuration -->
<ol>
    <li>      
      Para carregar o código fonte no nodeMCU foi usada a IDE do Arduíno
<!--       To load the source code in nodeMCU, the Arduino IDE was used.  -->
   </li>
   <li>
      Você pode precisar instalar o driver ch340: <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/tree/main/drivers">download aqui</a> (linux - testado em debian) ou <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/drivers/CH341SER_windows.zip">aqui</a> (windows).
<!--    You may need to install the ch340 driver <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/tree/main/drivers">here</a> (linux - tested on debian) or <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/drivers/CH341SER_windows.zip">here</a> (windows). -->
   </li>
   <li>
      Tutorial para instalar o ESP8266 na IDE Arduino <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/tutorials/nodeMcu_on_Arduino_IDE.md">aqui</a>
<!--             Tutorial to install ESP8266 on Arduino IDE <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/tutorials/nodeMcu_on_Arduino_IDE.md">here</a> -->
   </li>
</ol>

### Implementação
<!-- ### Implementation -->
<ol>
    <li>
       Abra o código fonte na IDE Arduino, selecione a placa *NodeMCU 1.0 (ESP12-E Module)*;
<!--       Open the source code in Arduino IDE, select board *NodeMCU 1.0 (ESP12-E Module)*. -->
   </li>
   <li>
       Conecte o módulo NodeMCU (cabo mini USB) na porta USB do seu computador para carregar o programa;
<!--       Plug NodeMCU module (Mini USB cable) on USB port from computer to load programm. -->
   </li>
   <li>
      Verifique se a placa foi devidamente conectada à IDE clicando em Ferramentas > Obter informações da placa;
<!--       Check if the board was connected; -->
   </li>
   <li>
      Carregue o código para a placa clicando no botão com uma seta no canto superior esquerdo da IDE (load).
<!--       Load the programm to board clicking on button with an arrow (load). -->
   </li>
 </ol>


## Raspberry Pi B (Sink):
#### Configuração
<p>
   
 O primeiro passo é habilitar o raspberry para que ele possa se conectar à internet a partir do wifi. O tutorial para habilitar a conexão está definida <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/tutorials/nodeMcu_on_Arduino_IDE.md"> aqui </a>
   
Seguidos o passo a passo definido no tutorial o dispositivo deve estar conectado à rede Wi-fi
#### Implementação:
<p>
   O Raspberry Pi deve, inicialmente, receber as informações enviadas pelos NodeMCUs e trata-las. Foi definido que a troca de mensagens entre os dispositivos seria feita a partir da utilização do procolo UDP.
   
   Para que o Raspberry seja capaz de receber os pacotes UDP foram utilizados os objetos sockets disponibilizados pelo Python. Definindo o IP e a porta pela qual o dispositivo espera receber as informações, os NodeMCU conseguem enviar seus pacotes desde que eles estejam direcionados para o IP definido no Raspberry.
   
   Ao receber a mensagem, os dados são dividos e depois armazenados em um dicionário de dados. Foi definido que depois do recebimento de um determinado número de mensagens, seria feito o backup da estrutura de dados que armazena todas as informações recebidas.
   
   <ul>
      <il>
          <a href="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/src/PGCC008_atividade_host/rasberry-server.py">
         Código fonte do servidor Raspberry Pi
       </a>
      </il>
   </ul>
   
</p>


<!-- ## Results -->
