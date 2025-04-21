import React from 'react'
import { View, Button, Text } from 'react-native';


export default function HomeScreen ({ navigation }) {
    return (
        <View>
            <Text>Tela home teste</Text>
            <Button title="Voltar para login" onPress={() => navigation.navigate('Login')}></Button>
        </View>
    );
}