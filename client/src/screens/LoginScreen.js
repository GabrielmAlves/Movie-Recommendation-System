import React from 'react';
import { View, Button, Text} from 'react-native';


export default function LoginScreen({ navigation }) {
    return (
      <View>
        <Text>Login test</Text>
        <Button title="Entrar" onPress={() => navigation.navigate('Home')}></Button>
      </View>  
    );
}