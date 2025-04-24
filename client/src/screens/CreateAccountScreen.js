import React from 'react'
import { View, Button, Text } from 'react-native';


export default function CreateAccountScreen ({ navigation }) {
    return (
        <View>
            <Text>Tela de criar conta teste</Text>
            <Button title="Voltar para login" onPress={() => navigation.navigate('Login')}></Button>
        </View>
    );
}