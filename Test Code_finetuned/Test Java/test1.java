import org.eclipse.paho.client.mqttv3.*;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

public class MqttSubscriber implements MqttCallback {

    private MqttClient client;
    private String broker;
    private String clientId;
    private String topic;
    private int qos;

    public MqttSubscriber(String broker, String clientId, String topic, int qos) {
        this.broker = broker;
        this.clientId = clientId;
        this.topic = topic;
        this.qos = qos;
    }

    public void connectAndSubscribe() throws MqttException {
        client = new MqttClient(broker, clientId, new MemoryPersistence());
        MqttConnectOptions options = new MqttConnectOptions();
        options.setCleanSession(true);
        client.connect(options);
        client.setCallback(this);
        client.subscribe(topic, qos);
    }

    public void disconnect() throws MqttException {
        client.disconnect();
    }

    @Override
    public void connectionLost(Throwable cause) {
        // Handle connection lost
    }

    @Override
    public void messageArrived(String topic, MqttMessage message) throws Exception {
        // Handle incoming message
        System.out.println("Received message: " + new String(message.getPayload()));
    }

    @Override
    public void deliveryComplete(IMqttDeliveryToken token) {
        // Handle delivery complete
    }
}