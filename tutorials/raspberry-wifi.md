## Tutorial para habilitar a conexão Wi-fi no Raspberry

Para que o Raspberry Pi seja capaz de se conectar à redes Wi-fi é necessário que dois arquivos específicos sejam modificados. Importante ressaltar que esse tutorial é desenvolvido para dispositivos com o sistema operacional Raspibian.
<p>
  1 - O primeiro arquivo a ser modificado é o arquivo responsável por definir as interfaces de rede do Raspberry, localizado em <it>/etc/network/interface</it>). A imagem mostra as informações importantes que devem ser contidas nesse arquivo para a continuação do processo de configuração.
  <br>
  <br>
  <img src="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/tutorials/arquivo_interface.png"  width = 50%>
  <br>
  <br>
  2 - O segundo passo envolve a edição do arquivo responsável por definir as características da rede com a qual se deseja conectar, incluindo nome e senha de acesso. Esse arquivo está localizado em <it>/etc/wpa_supplicant/wpa_supplicant.conf</it>
  <br>
  <br>
  <img src="https://github.com/angeload/pgcc008_2022-1_Probl1/blob/main/tutorials/wpa_supplicant_conf.png"  width = 45%>
  <br>
  A imagem a cima mostra como o arquivo deve ser definifo, onde SSID e psk representam o nome e a senha de acesso da rede, respectivamente.
</p>


<p>
 Seguidos os dois passos anteriores o dispositivo deve ser reiniciado. Ao liga-lo novamente é esperado que ele se conecte automaticamente à rede wifi desejada. No entanto,
  se essa conexão não acontecer de forma automática, é possível defini-la manualmente a partir da execução do comando:
  
  <code>sudo dhclient -v</code>
  
  Agora o Raspberry está conectado a rede e pronto para uso.
</p>
