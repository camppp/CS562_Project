function processPayments(payments, demande_batiment_moe) {
    return payments.map(payment => {
        return {
            montant_paiement: payment.montant_paiement,
            date_paiement: payment.date_paiement,
            observation: payment.observation,
            demande_batiment_moe: demande_batiment_moe
        };
    });
}