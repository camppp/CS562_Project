import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.MqttTopic;

public class MqttSubscriber {
   private MqttClient client;
   private MqttConnectOptions options;
   private MqttTopic topic;
   private int qos;

   public MqttSubscriber(String brokerUrl, String clientId, String topic, int qos) {
       this.client = new MqttClient(brokerUrl, clientId);
       this.options = new MqttConnectOptions();
       this.topic = new MqttTopic(topic);
       this.qos = qos;
   }

   public void connectAndSubscribe() throws MqttException {
       client.connect(options);
       client.subscribe(topic, qos);
   }

   public void disconnect() throws MqttException {
       client.disconnect();
   }

   public void handleMessage(MqttMessage message) {
       // Handle incoming message
   }
}